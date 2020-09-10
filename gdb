1、生成可调式的程序
	gcc -g（加参数g生成的程序可进行gdb调试）
2、启动gdb
	gdb appName	可以调试某个程序
	在启动调试某个程序后如果要传参数可以使用 set args var1 var2.....
3、调试命令
	运行程序：
		run(r)	运行程序
		continue(c) 	继续执行程序到下一个断点或者执行到程序结束
		next(n)		单步执行程序，遇到函数不进入函数内部
		step（s）	单歩执行，遇到函数进入函数内部
		untill		当在一个循环体内单歩执行时，可以用untill直接跳出循环体
		untill n	除了用来跳出循环体之外，还可以用来运行到指定的行数
		finish		运行程序，直到当前函数返回值
		call function	在程序启动以后，调用文件里面已声明的任意一个函数

	设置断点：
		break(b) n	在指定行设置断点
		b func		在函数func()入口处设置断点
		info（i）	查看断点设置情况
		delete(d) breakPointNum	删除断点
		disable breakPointNum	暂停断点
		enable	breakPointNum	开启断点
		delete	breakpoints	删除所有断点
		clear	n	删除第n行断点
	显示代码：
		l func	显示函数func();
	打印相关信息：
		print(p)	可以打印表达式或者变量值等
		print	fun（22）	以22作为参数调用函数fun（）
		print	fun（a）	以变量a为参数调用fun（）函数
		diaplay	a	每次单歩执行完之后都会打印变量a的值
		whatis var/funcName	查看函数类型和参数类型或者查看变量类型
		info	locals		查看当前页堆栈所有变量		
	分割窗口：
		layout	src	一个窗口显示调试信息，一个窗口显示源代码
		layout 	asm	显示反汇编窗口
		layout	regs	显示反汇编/寄存器窗口
		layout  split	显示源代码和反汇编窗口
		ctrl+l		刷新窗口
	查询运行信息：
		info program	查询程序是否在运行，以及停止原因
		set args 参数	设置运行时的参数
		show args	显示已经设置了的参数
		where		当前运行的堆栈列表
		up/down		改变堆栈显示的深度
		bt traceback	显示当前调用堆栈

