如何使用Git进行开发（使用Github作为Git服务器）
=============================================
> Author: Rye Yao  
## Git入门教程
可参考
* [官方帮助](https://help.github.com)
* [Git版本控制使用方法入门教程](http://www.uml.org.cn/pzgl/201204285.asp)

## Git管理策略
项目采用[这篇文章](http://www.ruanyifeng.com/blog/2012/07/git.html "Git分支管理策略")所描述的方法来进行Git协同开发，简单总结如下：
> 还可以参考[这篇文章](http://roclinux.cn/?p=2129 "GIT分支管理是一门艺术")

* *master*分支仅用于发布可部署的release版本，所有*临时性分支*均基于develop分支
* 团队所有成员均在远程仓库的*develop*分支的基础上进行开发
* 每个功能模块基于从*develop*分支分出的新分支*feature-xxx*进行开发
* 每个功能模块是否加入最终版本由项目管理者决定，由管理者进行所有*临时性分支*合并到*develop*分支以及*develop*分支合并（发布）到*master*分支的操作。

### 示例
以下用一个模拟开发过程来解释上述管理策略:
#### 准备
* 管理者创建了远程仓库*GitStartup*，并在*master*分支下创建了一些说明性文件和License文件
* 管理者在远程仓库创建了*develop*分支
> *develop*分支包含到其创建时刻为止*master*分支的所有文件
#### 开发
* Joe接到开发任务，被要求完成一个简单的聊天服务器
* Joe首先将远程仓库*GitStartup*的*develop*分支克隆到本地
    git clone -b develop https://github.com/5tream/GitStartup.git
> <-b>用来指定一个远程分支。
> 现在Joe在本地拥有了一份远程仓库*GitStartup*的*develop*分支的克隆
* Joe需要先完成一个Tcp server，于是他从*develop*分支中创建了一个临时性分支*feature-tcpserver*用于开发Tcp Server
    git checkout -b feature-tcpserver develop
> 该命令创建了一个名为*feature-tcpserver*的本地分支，并将工作分支切换到新分支
> 注意：命令执行后仅在本地创建了一个*feature-tcpserver*分支，所有更改在执行<"git push">之前都不会影响远程仓库
* Joe完成了Tcp server的开发，他将更改提交到本地仓库，并最后推送到远程仓库的*feature-tcpserver*分支
    git add .
    git commit -a -m "Finished tcp server"
    git push origin feature-tcpserver
> 这句代码将本地仓库的当前工作分支（即*feature-tcpserver*）推送到了远程仓库的*feature-tcpserver*分支，如果远程仓库没有这个分支，那么在代码被执行后该远程分支将会被创建。也可以用下面的代码显式指定待推送的本地分支
    git push origin feature-tcpserver:feature-tcpserver
> <:>之前是本地分支名，之后是远程分支名
自此Joe完成了tcp server的开发，他可以继续开发其他模块，同时等待管理者的处理结果。

