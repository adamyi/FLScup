### 题目描述

FLS信息学竞赛又拿了第一名，这让他的好机油SYX很开心（大雾）。于是SYX推倒了FLS，把他关到了一个自己设计的监狱里面。这个监狱是一个![](http://latex.codecogs.com/gif.latex?m%5Ctimes%20n)的网格，FLS想从他被关押的位置![](http://latex.codecogs.com/gif.latex?%5Cleft%20%28%20s_x%2C%20s_y%20%5Cright%20%29)移动到监狱出口![](http://latex.codecogs.com/gif.latex?%5Cleft%20%28%20e_x%2C%20e_y%20%5Cright%20%29)，但他每次只能可以向上下左右四个方向移动一格。

为了避免FLS逃脱，SYX安排了若干守卫在各自的位置上。SYX的&ldquo;守卫&rdquo;是一些位置固定的智能探测装置，一旦FLS与某个装置的直线距离小于等于R时，FLS就会被抓住。但FLS是很聪明的，所以他会选择最优的逃跑路线。

现在给你这些守卫的坐标，请计算**R至少为多少时，才能让FLS无法逃脱**。由于SYX是很可爱的小朋友，所以他不想太为难大家，**你只需要输出R的平方即可**。

### 输入描述

第一行两个整数m,n 表示监狱大小

第二行两个整数![](http://latex.codecogs.com/gif.latex?s_x%2C%20s_y)表示FLS的起点坐标

第三行两个整数![](http://latex.codecogs.com/gif.latex?e_x%2C%20e_y)表示FLS的终点坐标

接下来若干行，每行两个整数，分别表示守卫的横坐标和纵坐标

### 输出描述

一行，一个整数，是你的答案。

### 样例输入

~~~~
5 5
1 1
5 5
3 3
4 2
~~~~

### 样例输出

~~~~
4
~~~~

### 数据范围

![](http://latex.codecogs.com/gif.latex?m%2C%20n%20%5Cleqslant%201000) ，且各坐标均在合法范围内（即不会超过网格边界）。起点和终点坐标不同；起点和终点外的所有坐标也各不相同。

