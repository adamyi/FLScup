# \[数学\]0-8-4位置
### 题目描述

《神盾局特工》中，0-8-4是不明物体的代号。话说Agent Coulson的团队又遇到了新的0-8-4。这个0-8-4有闪烁的功能。每一分钟，它都会闪烁到一个新的位置。这让Agent May和Agent Ward很是头疼。经过Agent Simmons和Agent Fitz发现，如果我们把地球表面铺平再抽象成一个空间直角坐标系的yz平面，x轴表示时间，单位长度是1分钟，那么这个0-8-4的闪烁地点近似于一条直线。

我们假定其其运动轨迹为直线，且**要求这条直线到每个时刻测得的0-8-4坐标的距离的方差最小**。为了不让这个0-8-4落入坏人手中，Agent Skye通过卫星得到了前n分钟的闪烁地点在空间直角坐标系中的坐标。

现在FLS想加入神盾局，为了准时赶到0-8-4的位置并获得这个0-8-4，Agent Coulson给FLS了一个任务：编程求出从现在（**“现在”指第n分钟末**）开始m分钟后的0-8-4位置。据说FLS只用3分钟就搞定了——如果是你，能完成这个任务么？

### 输入描述

第一行包含两个整数n和m

接下来n行，每行2个整数y，z为这个0-8-4的y轴、z轴上的坐标。第i行表示的点的x坐标为i。

### 输出描述

输出包含2个小数y z表示从现在开始m分钟后0-8-4的y轴、z轴上的坐标，四舍五入保留到小数点后3位，有效数字小于等于15位。

样例输入

~~~
2 2
1 1
2 2
~~~

### 样例输出

~~~
4.000 4.000
~~~

### 数据范围

输入的y,z均小于等于6位

对于30%的数据，1&lt;n&lt;=300 1&lt;=m&lt;=150

对于100%的数据，1&lt;n,m&lt;=1000


