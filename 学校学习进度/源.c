#include <stdio.h>
#include <string.h>
#include <math.h>
int Jud(a)
{
	int i = 0;
	do
	{
		a = a / 10;
		i++;
	} while (a != 0);
	return i;
}
int Add(a, c)
{
	return a + c;
}
int Sub(a, c)
{
	return a - c;
}
int Mul(a, c)
{
	return a * c;
}
int Div(a, c)
{
	return a / c;
}
int main()
{
	int i = 0, a = 0, c[100], v = 1, w[100] = { 0 }, p = 0, k = 0, r = 0, s = 0;//a为第一项，c[100]为第二项及以后的数组
	int count = 0, j = 0, n = 0, d = 0, e = 0, f = 0, num = 1, m = 0, t = 0, y = 0;
	long int sum = 0;
	char b[100];
	printf("   +  -  加 减\n");
	printf("   ——  ——  (可识别+ - ×÷ * /)\n");
	printf("   × ÷ 乘 除\n");
	printf("\n");
	printf("101119328熊梓帆\n");
	printf("注意：\n");
	printf("(可计算至少20项连续计算)\n");
	printf("(可计算(-9999999, 9999999)的结果)\n");
	printf("(连续计算不显示乘除竖式)\n");
	printf("(连续计算除法保留整数)\n");
	printf("功能：\n");
	printf("1、整数四则运算\n2、能识别串式表达式输入\n");
	printf("3、竖式显示计算过程\n4、连续运算功能\n5、能判断先乘除后加减\n");
	printf("使用说明书：\n1：输入算式中的符号个数。\n2：输入算式（不可输错符号个数，退出重新输入）\n3：回车键结束输入\n");
end:
	for (y = 0; y < 100; y++)//清空三个数组的值，为后续循环
	{
		w[y] = 0;
		c[y] = 0;
		b[y] = 0;
	}
	num = 1;//num原输入数组c[100]的位置
	count = 0;//新存储数组w[100]的位置
	v = 1;//存储符号数组b[100]的位置
	printf("\n");
	printf("算式中符号个数：");
	scanf_s("%d", &f);
	printf("\n");
	printf("请输入算式：");
	scanf_s("%d", &a);
	r = a;//将a的值赋给r，全局保护
	for (j = 0; j < f; j++) //f：运算符的个数
	{
		scanf("%c", &b[j]);  //b[j]：运算符统计数组中
		scanf_s("%d", &c[j]);   //c[j]：第二位及后续常数变量
	}                   //w[100]：（存放经过乘除法运算）数组
	if (f > 1)        //排除简单两项式
	{
		for (p = 1; p <f; p++)    //p：特定循环变量
		{
			switch (b[p])        //检查从第二个开始的运算符
			{
			case'×':
				if (p == 1)
					w[count] = Mul(c[0], c[1]);
				else if ((b[p - 1] != '+' && b[p - 1] != '-') && p > 1) //前一位是乘除法
				{
					w[count] = Mul(w[count], c[num]);    //w[100]中结果再进行乘除
				}
				else if ((b[p - 1] == '+' || b[p - 1] == '-') && p > 1)  //前一位是加减
				{
					w[count] = Mul(c[num - 1], c[num]);
				}
				if (b[p + 1] == '+' || b[p + 1] == '-' || p == f - 1)  //后一位是加减
					count++;
				num++;   //num原输入数组c[100]的位置 
				break;
			case'*':
				if (p == 1)
					w[count] = Mul(c[0], c[1]);
				else if ((b[p - 1] != '+' && b[p - 1] != '-') && p > 1)  //前一位是乘除法
				{
					w[count] = Mul(w[count], c[num]);    //w[100]中结果再进行乘除
				}
				else if ((b[p - 1] == '+' || b[p - 1] == '-' )&& p > 1)    //前一位是加减
				{
					w[count] = Mul(c[num - 1], c[num]);
				}
				if (b[p + 1] == '+' || b[p + 1] == '-')   //判断后一位符号是加减
						count++;
				num++;   //num原输入数组c[100]的位置 
				break;
			case'÷':
				if (p == 1)
					w[count] = Div(c[0], c[1]);
				else if ((b[p - 1] != '+' && b[p - 1] != '-') && p > 1) //前一位是乘除法
				{
					w[count] = Div(w[count], c[num]);   //w[100]中结果再进行乘除
				}
				else if ((b[p - 1] == '+' || b[p - 1] == '-') && p > 1)   //前一位是加减
				{
					w[count] = Div(c[num - 1], c[num]);
				}
				if (b[p + 1] == '+' || b[p + 1] == '-' || p == f - 1)   //后一位是加减
					count++;
				num++; //num原输入数组c[100]的位置 
				break;
			case'/':
				if (p == 1)
					w[count] = Div(c[0], c[1]);
				else if ((b[p - 1] != '+' && b[p - 1] != '-') && p > 1) //前一位是乘除法
				{
					w[count] = Div(w[count], c[num]); //w[100]中结果再进行乘除
				}
				else if ((b[p - 1] == '+' || b[p - 1] == '-') && p > 1)  //前一位是加减
				{
					w[count] = Div(c[num - 1], c[num]);
				}
				if (b[p + 1] == '+' || b[p + 1] == '-' || p == f - 1)    //后一位是加减
					count++;
				num++;   //num原输入数组c[100]的位置 
				break;
			default:   //当前符号为加减
				b[v] = b[p];   //存储加减号
				if (p == f-1 )
				{
					if (f == 2)
					{
						w[count] = c[0];
						count++;
						w[count] = c[1];
					}
				    else if (f > 2)
					w[count] = c[p];
				}
				else if (b[p + 1] != '+' && b[p + 1] != '-' && p != f - 1)//后一位是乘除
				{
					if (p == 1)
					{
						w[count] = c[0];
						count++;
					}
					num++;   //num加一，继续计算后续数字
				}
				else if(b[p + 1] == '+'|| b[p + 1] == '-' && p != f -1)//后一位加减
				{
					if (p == 1)
					{
						w[count] = c[0];
						w[count + 1] = c[1];
						count+=2;
						num++;
					}
					else
					{
						w[count] = c[num];  //存储数字
						num++;
						count++;
					}
				}
				if (p < f) //注意v没有仔细分析
					v++;
				break;
			}
		}
		for (y = 0; y < 100; y++) //循环刷新，用于检测
			c[y] = 666;
		for (y = 0; y <= count; y++) //将新数组赋给原数组
			c[y] = w[y];
		f = v;   //根据符号数量v进行循环次数判断
	}
		for (j = 0; j < f; j++)
		{
			if (j > 0)
				a = sum;
			switch (b[j])   //加减法的分类调用
			{
			case '+':
				printf(" %10d\n", a);  //竖式搭建
				printf("%c", b[j]);
				printf("%10d\n", c[j]);
				printf("——————\n");
				sum = Add(a, c[j]);
				printf(" %10d\n", sum);
				if (f > 1)
				{
					if (j + 1 == f)      //多项式结果呈现
					{
						printf("结果：");
						printf("%d", r);
						for (y = 0; y < f; y++)
						{
							printf("%c", b[y]);
							printf("%d", c[y]);
						}
						printf("=%d\n", sum);
						goto end;
					}
					else
						printf("\n");
				}
				else    //单项式加法结果呈现
				{
					printf("结果：%d+%d=%d\n", r, c[j], sum);
					goto end;
				}
				break;
			case '-':
				printf(" %10d\n", a);   //竖式搭建
				printf("%c", b[j]);
				printf("%10d\n", c[j]);
				printf("——————\n");
				sum = Sub(a, c[j]);
				printf(" %10d\n", sum);
				if (f > 1)
				{
					if (j + 1 == f)       //多项式运算结果呈现
					{
						printf("结果：");
						printf("%d", r);
						for ( y= 0;  y< f; y++)
						{
							printf("%c", b[y]);
							printf("%d", c[y]);
						}
						printf("=%d\n", sum);
						goto end;
					}
					else
						printf("\n");
				}
			    else  //单项式加法结果呈现
				{
					printf("结果：%d-%d=%d\n", r, c[j], sum);
					goto end;
				}
				break;
			case '×':
				printf(" %10d\n", a);   //竖式搭建
				printf("%c", b[j]);
				printf("%10d\n", c[j]);
				printf("——————\n");
				k = Jud(a);
				sum = Mul(a, c[j]);
				for (i = 0; i < k; i++)  //竖式运算过程
				{
					d = a % 10;
					n = d * c[j];
					e = Jud(n);
					for (y = 0; y < 11 - i - e; y++)//对于结果右对齐
						printf(" ");
					printf("%d", n);
					printf("\n");
				}
				if (k > 1)
				{
					printf("——————\n");
					printf(" %10d\n", sum);
				}
				if (f > 1)//多项式处理
				{
					if (j + 1 == f)  //判断最后一步运算
					{
						printf("结果：");
						printf("%d", r);
						for (y = 0; y < f; y++)
						{
							printf("%c", b[y]);
							printf("%d", c[y]);
						}
						printf("=%d", sum);
						goto end;
					}
					else
						printf("\n");
				}
				else  //单项式运算
				{
					printf("结果：%d×%d=%d\n", r, c[j], sum);
					goto end;
				}
				break;
			case '÷':
				sum = Sub(a, c[j]);
				if (a < c[j])
					printf("error");
				else if (a >= c[j])
					if (a == 0)
						printf("error");
					else
					{
						k = Jud(a);
						sum = Div(a, c[j]);
						s = Jud(sum);
						t = sum;
						printf("      %10d\n", sum);
						printf("      ——————\n");
						printf("%5d|%10d\n", c[j], a);
						for (y = s - 1; y >= 0; y--)
						{
							d = t / pow(10, y);     //sum为求出的结果，d为sum所在位的数
							e = a - d * pow(10, y) * c[j];      //e为余数，a为被除数
							m = d * pow(10, y) * c[j];      //m为当前位数与除数的乘积
							printf("      %10d\n", m);
							printf("      ——————\n");
							printf("      %10d\n", e);
							a = e;
							t = Div(a, c[j]);
							while (e < c[j])  //循环直到最后一步结束竖式
								break;
						}
					}
				if (f > 1)
				{
					if (j + 1 == f)
					{
						printf("结果：");
						printf("%d", r);
						for (y = 0; y < f; y++)
						{
							printf("%c", b[y]);
							printf("%d", c[y]);
						}
						printf("=%d", sum);
						goto end;
					}
					else
						printf("\n");
				}
				else
				{
					printf("结果：%d/%d=%d……%d\n", r, c[j], sum, e);
					goto end;
				}
				break;
			  case '*':  //同x法
				printf(" %10d\n", a);
				printf("%c", b[j]);
				printf("%10d\n", c[j]);
				printf("——————\n");
				k = Jud(a);
				sum = Mul(a, c[j]);
				for (i = 0; i < k; i++)
				{
					d = a % 10;
					n = d * c[j];
					e = Jud(n);
					for (y = 0; y < 11 - i - e; y++)
						printf(" ");
					printf("%d", n);
					printf("\n");
				}
				if (k > 1)
				{
					printf("——————\n");
					printf(" %10d\n", sum);
				}
				if (f > 1)
				{
					if (j + 1 == f)
					{
						printf("结果：");
						printf("%d", r);
						for (y = 0; y < f; y++)
						{
							printf("%c", b[y]);
							printf("%d", c[y]);
						}
						printf("=%d", sum);
						goto end;
					}
					else
						printf("\n");
				}
				else
				{
					printf("结果：%d*%d=%d\n", r, c[j], sum);
					goto end;
				}
				break;
			case '/':
				sum = Sub(a, c[j]);
				if (a < c[j])
					printf("error");
				else if (a >= c[j])
					if (a == 0)
						printf("error");
					else
					{
						k = Jud(a);
						sum = Div(a, c[j]);
						s = Jud(sum);
						t = sum;
						printf("      %10d\n", sum);
						printf("      ——————\n");
						printf("%5d|%10d\n", c[j], a);
						for (y = s-1; y >=0; y--)
						{
							d = t / pow(10, y);   //sum为求出的结果，d为sum所在位的数
							e = a - d * pow(10, y)*c[j];    //e为余数，a为被除数
							m = d * pow(10, y) * c[j];     //m为所在位数0000
							printf("      %10d\n", m);
							printf("      ——————\n");
							printf("      %10d\n", e);
							a = e;
							t = Div(a, c[j]);
							while (e < c[j])
								break;
						}
					}
						if (f > 1)
						{
							if (j + 1 == f)
							{
								printf("结果：");
								printf("%d", r);
								for (y = 0; y < f; y++)
								{
									printf("%c", b[y]);
									printf("%d", c[y]);
								}
								printf("=%d", sum);
								goto end;
							}
							else
								printf("\n");
						}
						else
						{
							printf("结果：%d/%d=%d……%d\n", r, c[j], sum, e);
							goto end;
						}
				break;
			default:   //出错提示error并重新输入
				printf("error");
				goto end;
				break;
			}
		}
	return 0;
}