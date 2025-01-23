如何优雅地食用这个 C++ 语法笔记仓库？
1. 确保你拥有 **git** 并掌握一定的git知识
2. 确保你使用的笔记软件是 ==obsidian==
3. 确保你会使用github的基础功能
---
准备工作完毕，现在开始食用吧
**同步更新使用如下**
1. fork这个仓库
2. 到你fork好的仓库里，用git克隆下来这个仓库
3. 用 **obsidian** 打开这个仓库如下的路径：
	`D:\Code film\C++\memo\C++语法(新)`
4. 定期用git同步fork的仓库即可
---
非同步更新如下：
1. 使用git克隆这个仓库
	`git clone https://github.com/imicola/Questions-and-Impressions.git`
2. 用 **obsidian** 打开这个仓库如下的路径：
	`D:\Code film\C++\memo\C++语法(新)`
3. 如果想获取更新，可以用以下方法：

1. **添加上游仓库**  
   首先需要在你的本地 Git 仓库中添加一个指向原始仓库的远程仓库链接。假设你已经克隆了仓库到本地，并且当前目录已经在仓库内。你可以通过以下命令添加：
   ```bash
   git remote add upstream https://github.com/imicola/Questions-and-Impressions.git
   ```

这样做之后，你就有了两个远程仓库：`origin`（指向你 fork 的仓库）和 `upstream`（指向原始仓库）。

2. **获取上游仓库的更新**  
   接下来，使用 `git fetch` 命令来获取上游仓库的所有更新，但不会自动合并或修改你当前的工作目录。
```bash
git fetch upstream
```

3. **切换到主分支**  
   确保你在你的主分支上（对于大多数仓库来说，这个分支叫做 `main` 或者 `master`）。如果没有在该分支上，请切换过去：
   ```bash
   git checkout main  # 或者 git checkout master
   ```

4. **合并上游仓库的更新**  
   使用 `git merge` 命令将上游仓库的更新合并到你的本地主分支：
   ```bash
   git merge upstream/main  # 如果主分支名为main；若为master则替换为upstream/master
   ```
这一步会将上游仓库的最新更改合并到你的本地仓库中。

通过定期重复步骤 2 到 4，你可以确保你的本地仓库与原始仓库保持同步。