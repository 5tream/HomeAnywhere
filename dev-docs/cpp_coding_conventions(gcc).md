= GCC C++ Coding Conventions =

'''Status as of 2012-08-16''': The C++ coding conventions for GCC have been approved.  The contents of this page are now obsolete.  Please visit the official [[http://gcc.gnu.org/codingconventions.html|GCC Coding Conventions]] page for details.

This is a proposed set of coding conventions to be used when writing GCC in C++.  The intention is to develop this on the wiki, and move them to http://gcc.gnu.org/codingconventions.html when they are stable.

For some additional background information, please see [[http://gcc.gnu.org/ml/gcc/2010-05/msg00747.html|RFC:Switching implementation language to C++]]

== General Guidelines ==
 * C++ code must conform to the C++03 standard, with the addition that the {{{long long}}} type may be used if the host C++ compiler supports it.  (The treatment of {{{long long}}} remains the same as it is today.)  In addition, C++ code should conform to the C++11 standard. Select adaptation macros can enable exploiting some features of C++11 while still preserving correct C++03.

 * Every version of GCC must be buildable by the previous version of GCC. This rule helps ensure smooth development of the next version. However, it doesn't help so much when you do not have a previous version. So, the more important rule is that every version must bootstrap, which means that version can develop itself.  Note that this statement does not preclude a need to build GCC with other compilers.

 * We will periodically pick a stable version of GCC, and require that that version of GCC be able to build all versions of GCC up to and including the next stable version.  E.g., we may decide that all newer versions of GCC should be buildable with GCC 4.3.5.

 * It is desirable that it be possible to build GCC with C++ compilers other than GCC itself.  If testing reveals that reasonably recent versions of non-GCC C++ compilers cannot compile GCC, then GCC code should be adjusted accordingly. (Avoiding unusual language constructs helps immensely.)

 * Supporting libraries such as libiberty will continue to provide a C interface.  C++ may only be used in the directories `gcc`, `libcpp` and `fixincludes`.

 * All use of C++ features is subject to the decisions of the maintainers of the relevant components.  (This restates something that is always true for gcc, which is that component maintainers make the final decisions about those components.)

 * When it is reasonably possible, use of prohibited features of C++ gives some warning during bootstrap. So we would have perhaps a new warning `-Wgcc-cxx-style` which detects most "easy" violations of our own coding rules.

  * Indentation rules are defined to be compatible with some use of some pretty-printer like `astyle`, and code should be when possible indented automatically.

== C++ features ==
 * C++ is a complex language.  We do not want to use all aspects of it.

 * The following features of the C++ language may not be used in GCC code.
  * RTTI and {{{dynamic_cast}}} (these features may be permitted when certain non-default `--enable-checking` options are enabled so as to allow checkers to report dynamic types).
   * Disabling RTTI will save space in the compiler.  Checking the type of a class at runtime usually indicates a design problem.  If you need classes to behave differently at runtime, use a virtual method.  If you need to know the type of a class for some other reason, use an enum or a virtual member function that coverts a pointer to the more derived class. For example, {{{#!cplusplus
common_type *p = ....;
if (specific_type *q = p->to_specific ()) {
  // We have and can use a specific_type pointed to by q.
}
}}}
  * Exceptions and throw specifications
   * Current GCC code is not exception safe.  Disabling exceptions will permit the compiler itself to be slightly more optimized.
  * In particular, GCC may be built with `-fno-exceptions` and `-fno-rtti`.
  * These restrictions notwithstanding, newly written GCC code should be exception safe, to permit for future reconsideration of these standards.
   * Mark Mitchell: That would mean some relatively major changes in style.  For example, we'd have to get used to using auto_ptr, and, in general, using resource-acquisition-as-initialization everywhere.  Of course, I think it's good practice, but it's a relatively high bar.
   * [[LawrenceCrowl]]: {{{auto_ptr}}} is broken.  We should use {{{shared_ptr}}} instead, from TR1's {{{<memory>}}} header.
 * The following features of the C++ language should in general be avoided in GCC code.
  * Multiple inheritance.
   * Multiple inheritance is confusing and rarely useful.
  * Defining new templates (use of existing templates, e.g., from the standard library, is fine).
   * This may be overly cautious and may be relaxed over time.
  * Nested namespaces.
   * Not expected to be useful in the GCC code base. (Top-level namespaces are permitted.)
  * Conversion operators.
   * All conversions should be explicit named functions to avoid confusion
  * {{{using}}} statements.
   * In general a reference to a given name should mean the same thing in any GCC source file. Using declarations may be used in class definitions to manage names within an inheritance hierarchy.

 * The following features of the C++ language are explicitly permitted in GCC code.
  * Classes with public and private methods, data members, and constructors.
   * There are four special member functions: the default constructor, the copy constructor, the copy assignment operator, and the destructor. The compiler will usually provide a default implementation for these functions. If that default does the right thing, document the use of the default explicitly. Otherwise, define the function. Defining any of these functions may make the class non-POD, which can reduce its efficiency.
   * Constructors and destructors are often much larger than programmers expect. Prefer non-inline versions unless you have evidence that the inline version is needed.
   * Single argument constructors should always be declared {{{explicit}}} (implementing a warning for this is likely useful in general).
   * [[PaoloBonzini]]: Try to avoid copy constructors and assignment operators.  Anything that includes pointer members and a destructor should disable copy constructors and assignment operators by declaring `TypeName(const TypeName&); void operator=(const TypeName&);`  as private (maybe we will want a macro for this).
   * [[LawrenceCrowl]]: Classes generally are either value classes or identity classes.  Copy constructors and assignment operators are fine for value classes.  They are often not appropriate to identity classes.  These classes should delete, or disable, these functions.  Marking such functions as follows will enable compiling against both C++03 and C++11. {{{#!cplusplus
TypeName(const TypeName&) DELETED;
void operator=(const TypeName&) DELETED;
}}}
  * Use of the C++98 standard library, including the Standard Template Library.

 * The following features of the C++ language may be used with care when appropriate in GCC code.
  * Class inheritance.
   * Use public inheritance to describe 'is-a' relationships. Use private inheritance to reuse an existing class in the implementation of the current class. Use protected inheritance to reuse an existing class in the implementation of a class hierarchy. Private and protected inheritance should normally be avoided.
  * Virtual functions.
   * Using virtual functions increases the size of an object of an instance of the class by one pointer.  Therefore virtual functions must be avoided in objects which are widely allocated, such as an GIMPLE or RTL.  However, virtual functions are acceptable where we use hooks today.
   * [[LawrenceCrowl]]: Virtual functions can often reduce the size of objects by binding information into the virtual tables and the virtual functions.  For example, various type tags need not be present.  Other attributes can be inferred from type and more general information.  Other attributes can be inferred from extending the class hierarchy at the leaves.  So, even though trees are heavily allocated, it remains to be seen whether virtual functions would increase the size.
  * Function and method overloading.
   * Function overloading can be confusing.  However, in some cases introducing new function names adds little value, as in the current distinction between {{{build_index_type}}} and {{{build_index_2_type}}}.  Function overloading is permitted provided the overloaded functions are semantically identical or at least very similar.  Virtual functions should not be overloaded.
   * You may overload if the overloaded name supports an action notion.  For example, the C++ standard's notion of {{{swap}}}.
   * You may *not* overload when implicit conversions among argument types may yield unintended effects.  For example, {{{#!cplusplus
void swizzle (int arg);
void swizzle (const char *arg);
... swizzle (NULL); ...
}}} Results in an unintended call to the int overload on some systems.  In practice, the problem that this restriction addresses arises more from bad user-defined implicit conversion operators.  [[http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2007/n2437.pdf|ISO C++ N2437]] [[http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2008/n2514.html|ISO C++ N2514]]
   * You may overload if a single argument, in a single position, has multiple representations.  For example, {{{#!cplusplus
void append (const char *str);
void append (std::string str);
}}}
   * You may *not* overload if more than one argument constitutes the representation of some data notion.  For example, in {{{#!cplusplus
void register (int house, const char *street, int zipcode);
}}} the arguments are a representation of addresses.  Instead, the overload should be on addresses. {{{#!cplusplus
void register(const Address &addr);
}}} This restriction cannot apply to constructors, where the whole point is to collect representational data. {{{#!cplusplus
Address::Address (int house, const char *street, int zipcode);
}}}
   * Notwithstanding the restrictions above, you may overload to detect errors.  That is, if unsigned numbers are good, but signed numbers are bad, you could overload {{{#!cplusplus
void munch (unsigned int arg);
void munch (int arg);
}}} and simply not define the signed int version.  Anyone using it would get a link-time error.  The C++0x standard has a syntax that enables compile-time detection of the problem. {{{#!cplusplus
void munch (int arg) = delete;
}}} We can provide a macro compatible with both C++98 and C++11. {{{#!cplusplus
void munch (int arg) DELETED;
}}}

  * Default arguments.
   * Default arguments are another type of function/method overloading, and the same rules apply: it is permitted if the result is semantically identical.  Default arguments must always be POD values and may not run constructors.  Virtual functions should not have default arguments.  Default arguments cause confusion when attempting to take the address of a function.  They cause client code taking the address of a function to break when a default argument is replaced by a specialized overload.  So, default arguments should generally not be used in customer-facing interfaces.  Consider function overloading instead.
  * Operator overloading.
   * Operator overloading is only permitted in the following cases.
    * {{{operator<<}}} may be implemented as appropriate to print a value to a stream.
    * Operators may only be overloaded for types that implement numeric values, where the overloaded operators implement the usual numeric semantics.
    * {{{operator()}}} may be implemented as necessary for use with standard classes, such as for a {{{std::sort}}} comparator.
    * Appropriate operators required for iterators and smart pointers.  Try to avoid complex iterators (e.g. restrict to input iterators).
    * [[LawrenceCrowl]]: {{{operator[]}}} for data structures seems like a good use case. 

 * At least for now we will continue to use {{{printf}}} style I/O rather than {{{<iostream>}}} style I/O.  The latter should only be used in brand new areas, or after an agreed upon flag day transition.  Since GCC already type checks {{{printf}}} arguments, {{{<iostream>}}} does not bring any clear benefits.
  * LaurynasBiveinis: I propose to ban {{{<iostream>}}} style I/O in brand new areas too, as it needlessly complicates i18n, unless something like Boost Format is used. (I do not propose introduce Boost dependency; this is just an indication how IMHO C++ I/O should look like).
  * BasileStarynkevitch: I believe that for all debugging or dumping outputs<<FootNote(More precisely, any output which does not need to be internationalized or localized for a French or Chinese GCC user; and dump output is in that case (and a Gimple textual output also would be in that case).)>>, using {{{<iostream>}}} style I/O should become the norm, not the exception. In particular, because plugins (e.g. [[MELT]]) or other GCC extensions could be happy to output a dump into e.g. a memory stream, etc. And C++  {{{<iostream>}}} style is much cleaner for outputting in arbitrary streams, including memory, that {{{<cstdio>}}} 

 * Individual exceptions to the above rules may be made if the maintainers agree.  The existence of such exceptions does not imply that the rules may be avoided in other cases.

== C++ Coding Conventions ==
 * The general guideline is to continue to follow the current C coding conventions where they make sense.

 * All current GCC code uses a space between the function name and the left parenthesis in a function call.  Essentially all C++ code omits that space, which is more consistent with C++ syntax.  For the present we will retain the space.  It is possible that in the future we will switch the code with a flag day.

 * In new code variables which are used in a small scope should be defined at the point of first use, rather than at the top of the function.  Variables which are used throughout the function may be defined at the top of the function, as in C.

 * Templates.
  * Start template parameter names with a leading upper-case letter.
  * Specify template parameter and argument lists with spaces to the outside of the angle brackets. {{{#!cplusplus
template <typename Type> // template declaration header
sometype <Type> ::sometype () { ... } // constructor definition
somefunc <int> (3) // function call
}}}
 * Classes.
  * Indent all elements defined within the body of a class by two spaces.
  * All constructors should initialize all data members
    in the member initializer list.
    (If not, the compiler will implicitly initialize non-POD fields,
    and any initialization in the body of the constructor implies extra work.)
  * The names of methods and data members may be short as long as they are clear.
  * All data members should be private.
  * All data members should have names which end with an underscore. This convention highlights the extra overhead of access to fields over local variables.
  * Where appropriate, a data member may have an accessor method which does nothing but return the value of the member.  The name of such a method should be the same as the name of the member, without the trailing underscore.
  * When a method refers to a non-static data member, it should always qualify the reference with {{{this->}}}.
   * This makes it clear to the reader where the value is coming from.  It also means that if the class is later converted to a template, there will be no difficulties with two-phase name lookup.  It is understood that this convention is not used in all C++ code.  Note that this is not a real change from the existing C code, where there is no implicit {{{this->}}}.
    * JackLloyd: Should there be a warning to check this? Something like -Wno-implicit-this
    * [[LawrenceCrowl]]: This syntax places a unnecessary line-length burden on programmers.  The trailing underscore convention is sufficient to show that the value comes from a data member.  Because data members have a distinct naming convention from other symbols, the only problem with two-phase lookup would be a compile-time failure to find the a non-private field in a base class.  But these do not exist by the "only private data members" rule.
  * When defining a class, first define all public types, then all public constructors, then the public destructor, then all public methods.
    * [[LawrenceCrowl]]: Putting function bodies before data members makes for some uncomfortable class reading, as the context for interpreting the function bodies is not yet complete.  I would rather see data member definitions before function definitions or all function definitions pushed outside of the class definition.
  * Method bodies may only appear in the class definition if they are very short, no more than five lines, not including function header and braces.  Otherwise the method body should be defined outside of the class definition.
{{{#!cplusplus
class my_class {
 public:
  my_class()
    : field1_(0), field2_(NULL_TREE)
  { }

  // Meaningful comment.
  int
  field1()
  {
    return this->field1_;
  }

 private:
  // Comment about field1.
  int field1_;
  // Comment about field2.
  tree field2_;
};
}}}
  * [[LawrenceCrowl]]: There has been some objection to not having class member function definitions start at the beginning of a line. We could require all member functions to be defined out of line.

 * Note that the rules for classes do not apply to structs.  Structs continue to behave as before, and in particular there is no need to add a trailing underscore to field names.  (Note here we are making a distinction between structs and classes that does not technically exist within C++.  Nevertheless, it is a useful distinction and we wish to preserve it.)

 * When it is appropriate to use a child class with virtual functions, the virtual functions should all be declared as protected.  Code should explicitly distinguish between the interface which the parent class presents to users of the class (the public methods) and the interface which the child class implements (the protected virtual methods).  (The destructor is an exception here; a virtual destructor may and indeed normally should be public).

 * Definitions within the body of a namespace are not indented.

 * In general lines should be limited to 80 characters.  In C++ code function names are often longer.  If this would cause the first function parameter with its type to exceed 80 characters, it should appear on the next line indented four spaces.
{{{#!cplusplus
void
very_long_class_name::very_long_function_name(
    very_long_type_name arg)
{
}}}
 * [[LawrenceCrowl]] Sometimes the class qualifier and function name together exceed 80 characters.  In this case, break the line before the {{{::}}} operator.  We may wish to do so preemptively for all class member functions.
{{{#!cplusplus
void
very_long_template_class_name <with, a, great, many, arguments>
::very_long_function_name(
    very_long_type_name arg)
{
}}}
