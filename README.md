# 学习C语言

- [KR](./KR/) 是阅读《C程序设计语言》第二版 过程中写下的实例和练习题
- [a-modern-approach](./a-modern-approach/)是阅读《C语言程序设计 现代方法》第二版 过程中写下的实例和练习题
- [leetcoode](./leetcode/)是使用C语言对[leetcode](https://leetcode-cn.com)网站中的一些算法题的实现

## VSCode配置C语言开发环境

> <https://code.visualstudio.com/docs/cpp/config-wsl>

安装vscode插件

- WSL extention
- Microsoft C/C++ extension
  - need install in WSL: Ubuntu

在WSL的Ubuntu中安装gcc、gdb

```bash
apt install build-essential gdb
```

在WSL 项目目录下中打开vscode

```bash
code .
```

## vscode

- F9: toggle breakpoint
- F5: start execution
