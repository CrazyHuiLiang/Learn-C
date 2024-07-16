# C程序设计语言（第2版）

源代码文件名说明：

- 开头3位数字代表在书（中文版第二版）中出现的页数
- 如果程序为示例程序，则在中划线后描述实例主题；
- 如果程序是完成的练习题，则在字符e后跟练习题的题号

各章节笔记如下：

- [第1章 导言](./Chapter%201%20A%20Tutorial%20Introduction.md) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; p1 - p25
- [第2章 类型、运算符和表达式](./Chapter%202%20Types%2COperators%2Cand%20Expressions.md) p27 - p43
- [第3章 控制流](./Chapter%203%20Control%20Flow.md) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;p45 - p55
- [第4章 函数与程序结构](./Chapter%204%20Functions%20and%20Program%20Structure.md) &emsp;&emsp;&emsp;p57 - p78
- [第5章 指针与数组](./Chapter%205%20Pointers%20and%20Arrays.md) &emsp;&emsp;&emsp;&emsp;&emsp;p79 - p110
- [第6章 结构](./Chapter%206%20Structures.md) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;p111 - p132
- [第7章 输入与输出](./Chapter%207%20Input%20and%20Output.md) &emsp;&emsp;&emsp;&emsp;&emsp;p133 - p148
- [第8章 UNIX系统接口](./Chapter%208%20The%20UNIX%20System%20interface.md)&emsp;&emsp;&emsp;&emsp;p149 - p166
- [附录A 参考手册](./Appendix%20A%20Reference%20Manual.md) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;p167 - p218
- [附录B 标准库](./Appendix%20B%20Standard%20Library.md) &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;p219 - p240

## 是否可以将函数实现写在 .h 文件中

If you put code in there you can’t include this .h multiple times in multiple files because that would lead to multiple definition of the same things at link time. That’s why you usually declare things in the header (.h) file and then provide the definition in the .cpp
