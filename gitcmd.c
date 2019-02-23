
#if 1			//GIT操作 20190112
#if 1			//安装
在Windows上安装
开始菜单里找到“Git”->“Git Bash”
安装完成后，还需要最后一步设置，在命令行输入：
#endif
#if 1			//配置
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
$ git config --list
$ git config user.name	
#endif
#if 1			//生成SSH
$ ssh-keygen -t rsa -C "youremail@example.com"
生成文件在C盘user-->Administrator--->.ssh文件夹内，其中《id_rsa.pub》为要添加到远程段的密匙
#endif

#if 1			//创建仓库
$ mkdir learngit
$ cd learngit
$ pwd
/Users/michael/learngit
$ git init
Initialized empty Git repository in /Users/michael/learngit/.git/


#endif

#if 1			//分支管理
1、分支查询
$ git branch					//查询本地分支（列出所有分支当前分支+“*”表示）	
$ git branch -r					//查询远程分支
$ git branch -v					//查询本地分支
$ git branch -vv				//查询分支跟踪情况
$ git fetch --all;				//提取最新的统计信息
2、分支创建
$ git checkout -b dev			//创建本地分支，并切换到分支dev
$ git push origin master:dev	//创建远程分支 需要权限
git checkout -b dev origin/dev	//创建与远程对应的dev分支（这样的分支会跟踪远程分支）（需要先创建远程分支--》比如git push origin master:dev）
git checkout -b [branch] [remotename]/[branch]		//建立与远程同名的分支并跟踪
$ git checkout -b local origin/serverfix		(OK)//建立与远程不同名的分支并跟踪（local--->serverfix）
3、删除分支
$ git branch -d dev				//删除本地dev分支
$ git push origin --delete dev 	//删除远程分支
4、分支合并
$ git merge dev					//将dev分支合并到当前分支

5、分支切换
$ git checkout dev				//切换到dev分支

6、设置分支跟踪

$ git branch --set-upstream-to origin/dev dev 	//上面命令指定dev分支追踪origin/dev分支 （20190112成功）
7、跟踪后的推送命令
$ git pull origin				//直接将本地当前分支推送给远程

#endif

#if 1			//远程库
1、//------------克隆远程库到本地------------------------------------------------
$ git clone git@github.com:michaelliao/gitskills.git
2、查询
$ git remote
origin
$ git remote -v
origin  git@github.com:michaelliao/learngit.git (fetch)
origin  git@github.com:michaelliao/learngit.git (push)	
3、创建库
$ git remote add origin git@github.com:3137908255/GitTest.git
$ git remote add origin https://github.com/3137908255/GitTest.git

4、//------------创建远程origin的dev分支到本地----------------------------------
$ git checkout -b dev origin/dev
5、//------------删除远程仓库--origin------------------------------------------------
git remote rm [origin]
6、//------------推送分支--------------------------------------------------
推送分支，就是把该分支上的所有本地提交推送到远程库。推送时，要指定本地分支，
这样，Git就会把该分支推送到远程库对应的远程分支上：
$ git push origin master
$ git push origin dev
$ git push origin local:dev			将本地分支local推送到远程dev分支下。
7、//-----------推送现有项目到github---------------------------------------------------
push an existing repository from the command line
//https:
$ git remote add origin https://github.com/3137908255/GitTest.git
$ git push -u origin master
//ssh
or push an existing repository from the command line
git remote add origin git@github.com:3137908255/GitTest.git
git push -u origin master

$ git remote add origin https://gitee.com/3137908255/Stm32iap.git
$ git push -u origin master
注意：在网络上创建项目是可选择是否创建附带的文件（readme.md）这个时候推送本地的现有项目会不成功
（因为网络上有本地没有的文件，处理方法1：下载网络端的项目，合并到本地，再推送（咱未验证）；
方法2：在网上创建项目时不创建任何附带文件，即项目的内容以本地文件为准，推送成功）
8、//------------合并远程库到本地再提交（此时远程库有新内容而本地，需要在本地合并才能上传）-
$ git pull <远程主机名> <远程分支名>:<本地分支名>
git pull命令用于从另一个存储库或本地分支获取并集成(整合)。git pull命令的作用是：取回远程主机某个分支的更新，再与本地的指定分支合并，它的完整格式稍稍有点复杂
git pull [options] [<repository> [<refspec>…]]

$ git pull origin next:master
比如，要取回origin主机的next分支，与本地的master分支合并
如果远程分支(next)要与当前分支合并，则冒号后面的部分可以省略
$ git pull origin next
相当于下面的命令
$ git fetch origin
$ git merge origin/next
//****************************************************************
Git也允许手动建立追踪关系
$ git branch --set-upstream master origin/next	上面命令指定master分支追踪origin/next分支
$ git pull origin	

#endif

#if 1			//常用操作命令
注意：终止分页输出log的命令为操作一个按键“Q”键，即可停止输出
1、//---------------git 日志--分行显示---------------------------------------------
$ git log
commit 3628164fb26d48395383f8f31179f24e0882e1e0
2、//-------------git 日志--单行显示-------------------------------------------------
git log --graph --pretty=oneline --abbrev-commit	//带分支图示
git --no-pager log -p -3							//不分页输出
$ git log --pretty=oneline							//输出一行上
3628164fb26d48395383f8f31179f24e0882e1e0 append GPL
ea34578d5496d7dd233c827ed32a8cd576c5ee85 add distributed
cb926e7ea50ad11b8f9e909c05226233bf755030 wrote a readme file
需要友情提示的是，你看到的一大串类似 3628164...882e1e0的是commit id（版本号）
3、//---------------查看添加版本时的字符串（操作日志一般为版本简介）-------------
$ git reflog
ea34578 HEAD@{0}: reset: moving to HEAD^
3628164 HEAD@{1}: commit: append GPL
ea34578 HEAD@{2}: commit: add distributed
cb926e7 HEAD@{3}: commit (initial): wrote a readme file
4、// -------------- 恢复版本----上一个版本/上上个版本----------------------------------

$ git reset --hard HEAD^
HEAD is now at ea34578 add distributed
上一个版本就是HEAD^，上上一个版本就是HEAD^^	
5、// --------------- 恢复版本----恢复到指定版本--------------------------------
$ git reset --hard 3628164
HEAD is now at 3628164 append GPL
注意此命令可以恢复到任意指定值的版本号上去（关键是 --hard XXXX的值 配合git reflog命令使用）
6、// --------------- 从暂存区恢复到工作区（相当于测试git add命令的作用）-----------------------------------------------
$ git reset HEAD readme.txt
Unstaged changes after reset:
M       readme.txt
7、// --------------- 查看修改后不一样的地方-----------------------------------------------
$ git diff HEAD -- readme.txt 
$ git diff readme.txt 	
8、// ----------------------- 从库中提取文件到g工作区 -----------------------
$ git checkout -- file	
9、//----------------删除文件----------------------------------------------
$ rm test.txt				//可恢复文件
$ git rm test.txt 			//不可恢复文件
$ git checkout -- test.txt	

#endif
#if 1	标签管理
1、创建标签
1.1、//----------创建标签------默认标签是打在最新提交的commit上的----------------------------------------------
$ git tag v1.0
在Git中打标签非常简单，首先，切换到需要打标签的分支上：然后，敲命令git tag <name>就可以打一个新标签：
注意，标签不是按时间顺序列出，而是按字母排序的。
1.2、//创建带有说明的标签，用-a指定标签名，-m指定说明文字：
$ git tag -a v0.1 -m "version 0.1 released" 1094adb
1.3、//----------给历史-commit 打标签---------------------------------------------------
$ git tag v0.9 6224937		//注意6224937为历史commit号
2、//----------查看所有标签----------------------------------------------------
2.1、$ git tag
v1.0
2.2、查询历史commit号
$ git log --pretty=oneline --abbrev-commit
2.3、//----------查看标签详情---git show <tagname>-------------------------------------------------
$ git show v0.9
commit 622493706ab447b6bb37e4e2a2f276a20fed2ab4
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Thu Aug 22 11:22:08 2013 +0800

    add merge
3、//-----------删除标签---------------------------------------------------
$ git tag -d v0.1
Deleted tag 'v0.1' (was e078af9)
//////先删除本地标签
$ git tag -d v0.9
Deleted tag 'v0.9' (was 6224937)
/////然后删除远端标签
$ git push origin :refs/tags/v0.9
To git@github.com:michaelliao/learngit.git
 - [deleted]         v0.9
4、//----------推送标签到远程-git push origin <tagname>---------------------------------------------------
$ git push origin v1.0
Total 0 (delta 0), reused 0 (delta 0)
To git@github.com:michaelliao/learngit.git
 * [new tag]         v1.0 -> v1.0
//----------推送全部尚未推送到远程的本地标签----------------------------------------------------
$ git push origin --tags
Counting objects: 1, done.
Writing objects: 100% (1/1), 554 bytes, done.
Total 1 (delta 0), reused 0 (delta 0)
To git@github.com:michaelliao/learngit.git
 * [new tag]         v0.2 -> v0.2
 * [new tag]         v0.9 -> v0.9
//--------------------------------------------------------------





#endif

#if 1			//


#endif

#endif



// ----------------------------------------------------------------------------------------------






#if 1			//基本操作
//---------------安装Git-----------------------------------------------
void 安装Git()
{
在Windows上安装
开始菜单里找到“Git”->“Git Bash”
安装完成后，还需要最后一步设置，在命令行输入：	
}

//---------------设置 查询用户信息-----------------------------------------------
void gitconfig()
{
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"

$ git config --list
$ git config user.name	
}

//---------------创建版本库-----------------------------------------------
void gitinit()
{
$ mkdir learngit
$ cd learngit
$ pwd
/Users/michael/learngit

$ git init
Initialized empty Git repository in /Users/michael/learngit/.git/	
}

//---------------把文件添加到版本库-----------------------------------------------
void gitadd()
{
$ git add readme.txt
$ git commit -m "wrote a readme file"
[master (root-commit) cb926e7] wrote a readme file
 1 file changed, 2 insertions(+)
 create mode 100644 readme.txt	
//---------------------------------------
$ git add file1.txt
$ git add file2.txt file3.txt
$ git commit -m "add 3 files." 
 
}


//---------------git 日志--分行显示---------------------------------------------
void gitlog()
{
$ git log
commit 3628164fb26d48395383f8f31179f24e0882e1e0
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Tue Aug 20 15:11:49 2013 +0800

    append GPL

commit ea34578d5496d7dd233c827ed32a8cd576c5ee85
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Tue Aug 20 14:53:12 2013 +0800	

//-------------git 日志--单行显示-------------------------------------------------
$ git log --pretty=oneline
3628164fb26d48395383f8f31179f24e0882e1e0 append GPL
ea34578d5496d7dd233c827ed32a8cd576c5ee85 add distributed
cb926e7ea50ad11b8f9e909c05226233bf755030 wrote a readme file

需要友情提示的是，你看到的一大串类似 3628164...882e1e0的是commit id（版本号）

$ git reflog
ea34578 HEAD@{0}: reset: moving to HEAD^
3628164 HEAD@{1}: commit: append GPL
ea34578 HEAD@{2}: commit: add distributed
cb926e7 HEAD@{3}: commit (initial): wrote a readme file
}

//--------------恢复版本----上一个版本/上上个版本----------------------------------
void gitreset()
{
$ git reset --hard HEAD^
HEAD is now at ea34578 add distributed
上一个版本就是HEAD^，上上一个版本就是HEAD^^	

//---------------恢复版本----恢复到指定版本--------------------------------
$ git reset --hard 3628164
HEAD is now at 3628164 append GPL
注意此命令可以恢复到任意指定值的版本号上去（关键是 --hard XXXX的值 配合git reflog命令使用）
//---------------查看添加版本时的字符串（操作日志一般为版本简介）-------------

//---------------从暂存区恢复到工作区（相当于测试git add命令的作用）-----------------------------------------------
$ git reset HEAD readme.txt
Unstaged changes after reset:
M       readme.txt
}

//---------------查看修改后不一样的地方-----------------------------------------------
void gitdiff()
{
$ git diff HEAD -- readme.txt 
$ git diff readme.txt 	
}


// ----------------------- 从库中提取文件到g工作区 -----------------------
void gitcheckoutFile()
{
	$ git checkout -- file
	
//----------------删除文件----------------------------------------------
$ rm test.txt				//可恢复文件
$ git rm test.txt 			//不可恢复文件
$ git checkout -- test.txt	

}


#endif
#if 1	分支管理	
//--------------创建本地分支，然后切换到dev分支-------------------------------
void BanchGitCheckout()
{
$ git checkout -b dev
Switched to a new branch 'dev'
git checkout命令加上-b参数表示创建并切换，相当于以下两条命令：
$ git branch dev						//创建分支
$ git checkout dev						//切换分支$ git checkout master
Switched to branch 'dev'	
}

//--------------创建/删除远程分支------------------------------------------------
void BranchGitCreateRemote()
{
git checkout -b dev origin/dev		//创建与远程对应的dev分支（这样的分支会跟踪远程分支）
$ git push origin master:dev		创建 需要权限
$ git branch -r						查询 需要权限	

git push origin --delete dev 		//删除分支

}

void BanchCheck()
{
	//--------------查询分支--本地----------------------------------------------
$ git branch
* dev
  master
git branch命令会列出所有分支，当前分支前面会标一个*号

//--------------查询分支--远程----------------------------------------------
$ git branch -r
* dev
  master
git branch命令会列出所有分支，当前分支前面会标一个*号
}

//-------------合并分支----git merge命令用于合并指定分支到当前分支-----------------------
void BranchGitmerge()
{
$ git merge dev		
Updating d17efd8..fec145a
Fast-forward
 readme.txt |    1 +
 1 file changed, 1 insertion(+)	
}

 //------------删除分支--------------------------------------------------
 void BanchDeleted()
{
 $ git branch -d dev
Deleted branch dev (was fec145a).	
}

 //--------------------------------------------------------------
 小结
Git鼓励大量使用分支：
查看分支：git branch
创建分支：git branch <name>
切换分支：git checkout <name>
创建+切换分支：git checkout -b <name>
合并某分支到当前分支：git merge <name>
删除分支：git branch -d <name>
#endif
#if 1	远程库	
//------------生成SSH KEY--------------------------------------------------
void RemoteGenerateSSH()
{
	$ ssh-keygen -t rsa -C "youremail@example.com"
}


//------------添加远程库--------------------------------------------------
void RemoteAddRepo()
{
1、添加库：git remote add [shortname] [url]
2、添加KEY:SSH KEY到个人帐号
3、验证KEY
$ ssh -T git@github.com
成功：Hi tianqixin! You've successfully authenticated, but GitHub does not provide shell access.
失败：
The authenticity of host 'github.com (13.229.188.59)' can't be established.
RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
Are you sure you want to continue connecting (yes/no)? 

yes（输入）

Warning: Permanently added 'github.com,13.229.188.59' (RSA) to the list of known hosts.
Hi 3137908255! You've successfully authenticated, but GitHub does not provide shell access.	

$ git remote add origin git@github.com:3137908255/GitTest.git
$ git push -u origin master

$ git remote add origin https://github.com/3137908255/GitTest.git
$ git push -u origin master
}
//------------查看远程库的信息--------------------------------------------------
void RemoteCheckRepo()
{
$ git remote
origin

$ git remote -v
origin  git@github.com:michaelliao/learngit.git (fetch)
origin  git@github.com:michaelliao/learngit.git (push)	
}

//-----------推送现有项目到github---------------------------------------------------
void RemotePushRepo()
{
push an existing repository from the command line
//https:
$ git remote add origin https://github.com/3137908255/GitTest.git
$ git push -u origin master
//ssh
or push an existing repository from the command line
git remote add origin git@github.com:3137908255/GitTest.git
git push -u origin master


$ git remote add origin https://gitee.com/3137908255/Stm32iap.git
$ git push -u origin master
注意：在网络上创建项目是可选择是否创建附带的文件（readme.md）这个时候推送本地的现有项目会不成功
（因为网络上有本地没有的文件，处理方法1：下载网络端的项目，合并到本地，再推送（咱未验证）；
方法2：在网上创建项目时不创建任何附带文件，即项目的内容以本地文件为准，推送成功）
//------------推送分支--------------------------------------------------
推送分支，就是把该分支上的所有本地提交推送到远程库。推送时，要指定本地分支，
这样，Git就会把该分支推送到远程库对应的远程分支上：
$ git push origin master
$ git push origin dev
$ git push origin local:dev			将本地分支local推送到远程dev分支下。	
}

//------------抓取分支--------------------------------------------------
void RemoteCloneRepo()
{
现在，模拟一个你的小伙伴，可以在另一台电脑（注意要把SSH Key添加到GitHub）或者同一台电脑的另一个目录下克隆：
$ git clone git@github.com:michaelliao/learngit.git
Cloning into 'learngit'...
remote: Counting objects: 46, done.
remote: Compressing objects: 100% (26/26), done.
remote: Total 46 (delta 16), reused 45 (delta 15)
Receiving objects: 100% (46/46), 15.69 KiB | 6 KiB/s, done.
Resolving deltas: 100% (16/16), done.	

//------------克隆远程库到本地------------------------------------------------
$ git clone git@github.com:michaelliao/gitskills.git
}


//------------创建远程origin的dev分支到本地----------------------------------
$ git checkout -b dev origin/dev
//------------删除远程仓库--origin------------------------------------------------
git remote rm [origin]
//------------创建远程库-origin-------------------------------------------------
$ git remote add origin git@github.com:3137908255/GitTest.git
$ git remote add origin https://github.com/3137908255/GitTest.git

//------------合并远程库到本地再提交（此时远程库有新内容而本地，需要在本地合并才能上传）-
void BranchGitpull1()
{
$ git pull <远程主机名> <远程分支名>:<本地分支名>
git pull命令用于从另一个存储库或本地分支获取并集成(整合)。git pull命令的作用是：取回远程主机某个分支的更新，再与本地的指定分支合并，它的完整格式稍稍有点复杂
git pull [options] [<repository> [<refspec>…]]

$ git pull origin next:master
比如，要取回origin主机的next分支，与本地的master分支合并
如果远程分支(next)要与当前分支合并，则冒号后面的部分可以省略
$ git pull origin next
相当于下面的命令
$ git fetch origin
$ git merge origin/next
//****************************************************************
Git也允许手动建立追踪关系
$ git branch --set-upstream master origin/next	上面命令指定master分支追踪origin/next分支
$ git pull origin	
}
//------------合并远程库（dev分支）到本地库当前分支(local分支)------------------
//------------远程分支与本地分支互相更新------------------
void BranchGitpull2()
{
$ git pull origin dev:Local			提取远程指定分支（dev）到本地(Local)分支合并
$ git add xxx.txt					增加内容提交更新
$ git commit -m " "					递交到本地库
$ git push origin Local:dev			上传本地分支（Local）到远程库origin远程分支（dev）
Password authentication
Password:
}
//----------分支跟踪（远程与本地分支跟踪）--------------------
void BranchTrack()
{
git checkout -b [branch] [remotename]/[branch]
//建立与远程同名的分支并跟踪
$ git checkout --track origin/serverfix
Branch serverfix set up to track remote branch serverfix from origin.
Switched to a new branch 'serverfix'
//建立与远程不同名的分支并跟踪（local--->serverfix）
$ git checkout -b local origin/serverfix		(OK)	
Branch local set up to track remote branch serverfix from origin.
Switched to a new branch 'local'
//设置已有的本地分支跟踪一个刚刚拉取下来的远程分支，或者想要修改正在跟踪的上游分支
//使用 -u 或 --set-upstream-to 
$ git branch -u origin/serverfix
Branch serverfix set up to track remote branch serverfix from origin.
$ git branch --set-upstream-to master origin/next	上面命令指定master分支追踪origin/next分支

//查看跟踪情况（）
$ git fetch --all;		//提取最新的统计信息
$ git branch -vv		//显示跟踪信息

//跟踪后的推送命令
$ git pull origin
	
}


#endif

#if 1
//------------克隆远程库到本地------------------------------------------------
git clone git@github.com:michaelliao/gitskills.git
//查看跟踪情况（）
$ git fetch --all;		//提取最新的统计信息
$ git branch -vv		//显示跟踪信息
  dev    3855b2f [origin/dev] add test.txt
* local  3855b2f add test.txt
  master 3855b2f [origin/master] add test.txt
// ----------------------------------------追踪分支
git checkout -b dev1 origin/dev2						//创建本地dev1分支追踪远程dev2分支	
git branch --set-upstream-to master origin/next			//指定master分支追踪origin/next分支
git branch --set-upstream-to dev1 origin/dev2			//指定dev1分支追踪origin/dev2分支
git pull		//追踪之后可使用
git push		//追踪之后可使用
// ----------------------------------------非跟踪分支的更新
$ git pull origin dev:Local			//提取远程指定分支（dev）到本地(Local)分支合并
$ git add xxx.txt					//增加内容提交更新
$ git commit -m " "					//递交到本地库
$ git push origin Local:dev			//上传本地分支（Local）到远程库origin远程分支（dev）
// ----------------------------------------
//------------创建远程库-origin-------------------------------------------------
$ git remote add origin git@github.com:3137908255/GitTest.git
$ git remote add origin https://github.com/3137908255/GitTest.git
//------------生成SSH KEY--------------------------------------------------
ssh-keygen -t rsa -C "youremail@example.com"



#endif


//--------------------------------------------------------------


void GitCmdList1()
{	
	Git命令参考手册(文本版)
git init                                                  # 初始化本地git仓库（创建新仓库） 
git config --global user.name "xxx"                       # 配置用户名 
git config --global user.email "xxx@xxx.com"              # 配置邮件 
git config --global color.ui true                         # git status等命令自动着色 
git config --global color.status auto 
git config --global color.diff auto 
git config --global color.branch auto 
git config --global color.interactive auto 
git clone git+ssh://git@192.168.53.168/VT.git             # clone远程仓库 
git status                                                # 查看当前版本状态（是否修改） 
git add xyz                                               # 添加xyz文件至index 
git add .                                                 # 增加当前子目录下所有更改过的文件至index 
git commit -m 'xxx'                                       # 提交 
git commit --amend -m 'xxx'                               # 合并上一次提交（用于反复修改） 
git commit -am 'xxx'                                      # 将add和commit合为一步 
git rm xxx                                                # 删除index中的文件 
git rm -r *                                               # 递归删除 
git log                                                   # 显示提交日志 
git log -1                                                # 显示1行日志 -n为n行 
git log -5
git log --stat                                            # 显示提交日志及相关变动文件 
git log -p -m 
git show dfb02e6e4f2f7b573337763e5c0013802e392818         # 显示某个提交的详细内容 
git show dfb02                                            # 可只用commitid的前几位 
git show HEAD                                             # 显示HEAD提交日志 
git show HEAD^                                            # 显示HEAD的父（上一个版本）的提交日志 ^^为上两个版本 ^5为上5个版本 
git tag                                                   # 显示已存在的tag 
git tag -a v2.0 -m 'xxx'                                  # 增加v2.0的tag 
git show v2.0                                             # 显示v2.0的日志及详细内容 
git log v2.0                                              # 显示v2.0的日志 
git diff                                                  # 显示所有未添加至index的变更 
git diff --cached                                         # 显示所有已添加index但还未commit的变更 
git diff HEAD^                                            # 比较与上一个版本的差异 
git diff HEAD -- ./lib                                    # 比较与HEAD版本lib目录的差异 
git diff origin/master..master                            # 比较远程分支master上有本地分支master上没有的 
git diff origin/master..master --stat                     # 只显示差异的文件，不显示具体内容 
git remote add origin git+ssh://git@192.168.53.168/VT.git # 增加远程定义（用于push/pull/fetch） 
git branch                                                # 显示本地分支 
git branch --contains 50089                               # 显示包含提交50089的分支 
git branch -a                                             # 显示所有分支 
git branch -r                                             # 显示所有原创分支 
git branch --merged                                       # 显示所有已合并到当前分支的分支 
git branch --no-merged                                    # 显示所有未合并到当前分支的分支 
git branch -m master master_copy                          # 本地分支改名 
git checkout -b master_copy                               # 从当前分支创建新分支master_copy并检出 
git checkout -b master master_copy                        # 上面的完整版 
git checkout features/performance                         # 检出已存在的features/performance分支 
git checkout --track hotfixes/BJVEP933                    # 检出远程分支hotfixes/BJVEP933并创建本地跟踪分支
git checkout v2.0                                         # 检出版本v2.0
git checkout -b devel origin/develop                      # 从远程分支develop创建新本地分支devel并检出 
git checkout -- README                                    # 检出head版本的README文件（可用于修改错误回退） 
git merge origin/master                                   # 合并远程master分支至当前分支 
git cherry-pick ff44785404a8e                             # 合并提交ff44785404a8e的修改 
git push origin master                                    # 将当前分支push到远程master分支 
git push origin :hotfixes/BJVEP933                        # 删除远程仓库的hotfixes/BJVEP933分支 
git push --tags                                           # 把所有tag推送到远程仓库 
git fetch                                                 # 获取所有远程分支（不更新本地分支，另需merge） 
git fetch --prune                                         # 获取所有原创分支并清除服务器上已删掉的分支 
git pull origin master                                    # 获取远程分支master并merge到当前分支 
git mv README README2                                     # 重命名文件README为README2 
git reset --hard HEAD                                     # 将当前版本重置为HEAD（通常用于merge失败回退） 
git rebase 
git branch -d hotfixes/BJVEP933                           # 删除分支hotfixes/BJVEP933（本分支修改已合并到其他分支） 
git branch -D hotfixes/BJVEP933                           # 强制删除分支hotfixes/BJVEP933 
git ls-files                                              # 列出git index包含的文件 
git show-branch                                           # 图示当前分支历史 
git show-branch --all                                     # 图示所有分支历史 
git whatchanged                                           # 显示提交历史对应的文件修改 
git revert dfb02e6e4f2f7b573337763e5c0013802e392818       # 撤销提交dfb02e6e4f2f7b573337763e5c0013802e392818 
git ls-tree HEAD                                          # 内部命令：显示某个git对象 
git rev-parse v2.0                                        # 内部命令：显示某个ref对于的SHA1 HASH 
git reflog                                                # 显示所有提交，包括孤立节点 
git show HEAD@{5} 
git show master@{yesterday}                               # 显示master分支昨天的状态 
git log --pretty=format:'%h %s' --graph                   # 图示提交日志 
git show HEAD~3
git show -s --pretty=raw 2be7fcb476 
git stash                                                 # 暂存当前修改，将所有至为HEAD状态 
git stash list                                            # 查看所有暂存 
git stash show -p stash@{0}                               # 参考第一次暂存 
git stash apply stash@{0}                                 # 应用第一次暂存 
git grep "delete from"                                    # 文件中搜索文本“delete from” 
git grep -e '#define' --and -e SORT_DIRENT 
git gc 
git fsck
}
	
void GitCmdList2()
{
	Git 是一个很强大的分布式版本控制系统。它不但适用于管理大型开源软件的源代码，管理私人的文档和源代码也有很多优势。
Git常用操作命令：
1) 远程仓库相关命令
检出仓库：$ git clone git://github.com/jquery/jquery.git
查看远程仓库：$ git remote -v
添加远程仓库：$ git remote add [name] [url]
删除远程仓库：$ git remote rm [name]
修改远程仓库：$ git remote set-url --push [name] [newUrl]
拉取远程仓库：$ git pull [remoteName] [localBranchName]
推送远程仓库：$ git push [remoteName] [localBranchName]
 
*如果想把本地的某个分支test提交到远程仓库，并作为远程仓库的master分支，或者作为另外一个名叫test的分支，如下：
$git push origin test:master         // 提交本地test分支作为远程的master分支
$git push origin test:test              // 提交本地test分支作为远程的test分支
 
2）分支(branch)操作相关命令
查看本地分支：$ git branch
查看远程分支：$ git branch -r
创建本地分支：$ git branch [name] ----注意新分支创建后不会自动切换为当前分支
切换分支：$ git checkout [name]
创建新分支并立即切换到新分支：$ git checkout -b [name]
删除分支：$ git branch -d [name] ---- -d选项只能删除已经参与了合并的分支，对于未有合并的分支是无法删除的。如果想强制删除一个分支，可以使用-D选项
合并分支：$ git merge [name] ----将名称为[name]的分支与当前分支合并
创建远程分支(本地分支push到远程)：$ git push origin [name]
删除远程分支：$ git push origin :heads/[name] 或 $ gitpush origin :[name] 
 
*创建空的分支：(执行命令之前记得先提交你当前分支的修改，否则会被强制删干净没得后悔)
$git symbolic-ref HEAD refs/heads/[name]
$rm .git/index
$git clean -fdx
 
3）版本(tag)操作相关命令
查看版本：$ git tag
创建版本：$ git tag [name]
删除版本：$ git tag -d [name]
查看远程版本：$ git tag -r
创建远程版本(本地版本push到远程)：$ git push origin [name]
删除远程版本：$ git push origin :refs/tags/[name]
合并远程仓库的tag到本地：$ git pull origin --tags
上传本地tag到远程仓库：$ git push origin --tags
创建带注释的tag：$ git tag -a [name] -m 'yourMessage'
 
4) 子模块(submodule)相关操作命令
添加子模块：$ git submodule add [url] [path]
   如：$git submodule add git://github.com/soberh/ui-libs.git src/main/webapp/ui-libs
初始化子模块：$ git submodule init  ----只在首次检出仓库时运行一次就行
更新子模块：$ git submodule update ----每次更新或切换分支后都需要运行一下
删除子模块：（分4步走哦）
 1) $ git rm --cached [path]
 2) 编辑“.gitmodules”文件，将子模块的相关配置节点删除掉
 3) 编辑“ .git/config”文件，将子模块的相关配置节点删除掉
 4) 手动删除子模块残留的目录
 
5）忽略一些文件、文件夹不提交
在仓库根目录下创建名称为“.gitignore”的文件，写入不需要的文件夹名或文件，每个元素占一行即可，如
target
bin
*.db
 
=====================
Git 常用命令
git branch 查看本地所有分支
git status 查看当前状态 
git commit 提交 
git branch -a 查看所有的分支
git branch -r 查看本地所有分支
git commit -am "init" 提交并且加注释 
git remote add origin git@192.168.1.119:ndshow
git push origin master 将文件给推到服务器上 
git remote show origin 显示远程库origin里的资源 
git push origin master:develop
git push origin master:hb-dev 将本地库与服务器上的库进行关联 
git checkout --track origin/dev 切换到远程dev分支
git branch -D master develop 删除本地库develop
git checkout -b dev 建立一个新的本地分支dev
git merge origin/dev 将分支dev与当前分支进行合并
git checkout dev 切换到本地dev分支
git remote show 查看远程库
git add .
git rm 文件名(包括路径) 从git中删除指定文件
git clone git://github.com/schacon/grit.git 从服务器上将代码给拉下来
git config --list 看所有用户
git ls-files 看已经被提交的
git rm [file name] 删除一个文件
git commit -a 提交当前repos的所有的改变
git add [file name] 添加一个文件到git index
git commit -v 当你用－v参数的时候可以看commit的差异
git commit -m "This is the message describing the commit" 添加commit信息
git commit -a -a是代表add，把所有的change加到git index里然后再commit
git commit -a -v 一般提交命令
git log 看你commit的日志
git diff 查看尚未暂存的更新
git rm a.a 移除文件(从暂存区和工作区中删除)
git rm --cached a.a 移除文件(只从暂存区中删除)
git commit -m "remove" 移除文件(从Git中删除)
git rm -f a.a 强行移除修改后文件(从暂存区和工作区中删除)
git diff --cached 或 $ git diff --staged 查看尚未提交的更新
git stash push 将文件给push到一个临时空间中
git stash pop 将文件从临时空间pop下来
---------------------------------------------------------
git remote add origin git@github.com:username/Hello-World.git
git push origin master 将本地项目给提交到服务器中
-----------------------------------------------------------
git pull 本地与服务器端同步
-----------------------------------------------------------------
git push (远程仓库名) (分支名) 将本地分支推送到服务器上去。
git push origin serverfix:awesomebranch
------------------------------------------------------------------
git fetch 相当于是从远程获取最新版本到本地，不会自动merge
git commit -a -m "log_message" (-a是提交所有改动，-m是加入log信息) 本地修改同步至服务器端 ：
git branch branch_0.1 master 从主分支master创建branch_0.1分支
git branch -m branch_0.1 branch_1.0 将branch_0.1重命名为branch_1.0
git checkout branch_1.0/master 切换到branch_1.0/master分支
du -hs

-----------------------------------------------------------
mkdir WebApp
cd WebApp
git init
touch README
git add README
git commit -m 'first commit'
git remote add origin git@github.com:daixu/WebApp.git
git push -u origin master
}



void GitCmdList3()
{
一、 Git 常用命令速查
git branch 查看本地所有分支
git status 查看当前状态 
git commit 提交 
git branch -a 查看所有的分支
git branch -r 查看远程所有分支
git commit -am "init" 提交并且加注释 
git remote add origin git@192.168.1.119:ndshow
git push origin master 将文件给推到服务器上 
git remote show origin 显示远程库origin里的资源 
git push origin master:develop
git push origin master:hb-dev 将本地库与服务器上的库进行关联 
git checkout --track origin/dev 切换到远程dev分支
git branch -D master develop 删除本地库develop
git checkout -b dev 建立一个新的本地分支dev
git merge origin/dev 将分支dev与当前分支进行合并
git checkout dev 切换到本地dev分支
git remote show 查看远程库
git add .
git rm 文件名(包括路径) 从git中删除指定文件
git clone git://github.com/schacon/grit.git 从服务器上将代码给拉下来
git config --list 看所有用户
git ls-files 看已经被提交的
git rm [file name] 删除一个文件
git commit -a 提交当前repos的所有的改变
git add [file name] 添加一个文件到git index
git commit -v 当你用－v参数的时候可以看commit的差异
git commit -m "This is the message describing the commit" 添加commit信息
git commit -a -a是代表add，把所有的change加到git index里然后再commit
git commit -a -v 一般提交命令
git log 看你commit的日志
git diff 查看尚未暂存的更新
git rm a.a 移除文件(从暂存区和工作区中删除)
git rm --cached a.a 移除文件(只从暂存区中删除)
git commit -m "remove" 移除文件(从Git中删除)
git rm -f a.a 强行移除修改后文件(从暂存区和工作区中删除)
git diff --cached 或 $ git diff --staged 查看尚未提交的更新
git stash push 将文件给push到一个临时空间中
git stash pop 将文件从临时空间pop下来
---------------------------------------------------------
git remote add origin git@github.com:username/Hello-World.git
git push origin master 将本地项目给提交到服务器中
-----------------------------------------------------------
git pull 本地与服务器端同步
-----------------------------------------------------------------
git push (远程仓库名) (分支名) 将本地分支推送到服务器上去。
git push origin serverfix:awesomebranch
------------------------------------------------------------------
git fetch 相当于是从远程获取最新版本到本地，不会自动merge
git commit -a -m "log_message" (-a是提交所有改动，-m是加入log信息) 本地修改同步至服务器端 ：
git branch branch_0.1 master 从主分支master创建branch_0.1分支
git branch -m branch_0.1 branch_1.0 将branch_0.1重命名为branch_1.0
git checkout branch_1.0/master 切换到branch_1.0/master分支
du -hs
git branch 删除远程branch
git push origin :branch_remote_name
git branch -r -d branch_remote_name
-----------------------------------------------------------
初始化版本库，并提交到远程服务器端
mkdir WebApp
cd WebApp
git init 本地初始化
touch README
git add README 添加文件
git commit -m 'first commit'
git remote add origin git@github.com:daixu/WebApp.git
增加一个远程服务器端
上面的命令会增加URL地址为'git@github.com:daixu/WebApp.git'，名称为origin的远程服务器库，以后提交代码的时候只需要使用 origin别名即可	
	
}

//












