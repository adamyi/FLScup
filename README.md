# About FLS Cup

FLSCup is an OI competition held on Contest Hunter on June 6, 2014.


# Original info on Contest Hunter

<p>下次再也不出这么难了。。。</p>

<h3><strong>恭喜前五名获奖选手：</strong></h3>

<pre>
<a href="http://www.contesthunter.org/user/luoruixuan" style="color: rgb(255, 140, 0); text-decoration: none; font-family: 'Helvetica Neue', Helvetica, Arial, 'Microsoft YaHei', 'WenQuanYi Micro Hei', SimHei, sans-serif; font-size: 14px; line-height: 20px;" title="猎手(Hunter)">luoruixuan</a> <strong>565</strong>

<a href="http://www.contesthunter.org/user/390467054" style="color: rgb(0, 153, 204); text-decoration: none; font-family: 'Helvetica Neue', Helvetica, Arial, 'Microsoft YaHei', 'WenQuanYi Micro Hei', SimHei, sans-serif; font-size: 14px; line-height: 20px;" title="大牛(Bull)">390467054</a> <strong>200</strong>

<a href="http://www.contesthunter.org/user/Demon_Hunter" style="color: rgb(0, 128, 0); text-decoration: none; font-family: 'Helvetica Neue', Helvetica, Arial, 'Microsoft YaHei', 'WenQuanYi Micro Hei', SimHei, sans-serif; font-size: 14px; line-height: 20px;" title="领先学习者(Advanced Learner)">Demon_Hunter</a> <strong>170</strong>

<a href="http://www.contesthunter.org/user/faebdc" style="color: rgb(0, 153, 204); text-decoration: none; font-family: 'Helvetica Neue', Helvetica, Arial, 'Microsoft YaHei', 'WenQuanYi Micro Hei', SimHei, sans-serif; font-size: 14px; line-height: 20px;" title="大牛(Bull)">faebdc</a> <strong>140</strong>

<a href="http://www.contesthunter.org/user/lby2013" style="color: rgb(0, 128, 0); text-decoration: none; font-family: 'Helvetica Neue', Helvetica, Arial, 'Microsoft YaHei', 'WenQuanYi Micro Hei', SimHei, sans-serif; font-size: 14px; line-height: 20px;" title="领先学习者(Advanced Learner)">lby2013</a> <strong>100</strong></pre>

<h2><strong>请获奖者于比赛结束后3天内联系adamyi，否则视为放弃奖品</strong></h2>

<center>
<p>----------------------------------------华丽丽的分割线----------------------------------------</p>
</center>

<h4>简易题解：</h4>

<pre class="p1">
<strong>第一题 真心水题</strong>

就是线性回归拟合直线，使用两次最小二乘法即可，不会自行wikipedia（不要看百度百科，印象中wikipedia比百度百科讲得好）</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第二题 稍微有点麻烦的水题</strong>

字符串处理，分解算式，合并同类项。对于FLS表示法，a^b mod c= ((a^d mod c)^10 mod c * a^e mod c) mod c (e=b mod 10，d=(b-e)/10） 这样有效避免高精度 最后解方程，对于三次方程，可采用因式定理或盛金公式或卡尔丹公式</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第三题 水题</strong>

贪心+高精，让高兴系数大的自己喝一杯，最后只省一杯的钱其余所有人共用。前4点送分，后六点考察高精和大数据量处理速度，对于c语言，scanf超时，建议使用fread。</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第四题 简单网络流（搜索）</strong>

推荐可行算法网络流（由于测试数据弱，搜索AC无压力）。左上角原点，右下角汇点。因多机器人可同时间占据同一位置，将地图中每个点分成两个点(x,y,0)(x,y,1)。网络模型构造：原点s=v(1,1,0)汇点t=v(p,q,1)；在顶点中加入三种类型边e1,e2,e3，容量费用分别记为c1,c2,c3 w1,w2,w3 则 u e1 = v(x, y, 0) -&gt; v(x, y, 1),c1 = MaxInt,w1 = 0。 u e2 = v(x, y, 0) -&gt; v(x, y, 1)，c2 = 1，w2 = -1（这里要求(x, y)必须是植物） u e3 = v(x, y, 1) -&gt; v(x&#39;, y&#39;, 0)，c3 = MaxInt,w3 = 0. 其中x&#39;=x+1 y&#39;=y 或x&#39;=x y&#39;=y+1,1 &lt;= x&#39; &lt;= MaxX，1 &lt;= y&#39; &lt;= MaxY，且(x&#39; y&#39;)非障碍。求流量为n的固定最小费用流。</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第五题 动态规划</strong>

DP，O(MlogM)。W[i]表示第i列最上方（即y坐标最大）的守卫的y坐标。F[i,j]=sqrt((i-j)^2+(s-W[j])^2)表示当前行第i列与第j列最上方的守卫的距离。同理计算出每点上方最近守卫G[i]=min{F[i,j]}表示离当前行第i列最近的守卫的距离。C[i]表示离当前行第i列最近的守卫所在的列，即F[i,C[i]]=G[i]。C[i]一定非降（自行证明），之后二分。</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第六题 关键词查找（语义分析）</strong>

查找所有对于增加、减少的关键词，分析每个出现数字是增加还是减少，注意可能出现如give 3 to&hellip;, 2 to ...的情况。其中1个点需分析主语、宾语，不易拿分，其他4个点想拿分其实不难。</pre>

<p class="p1">&nbsp;</p>

<pre class="p1">
<strong>第七题 AI 略</strong></pre>

<p class="p2">&nbsp;</p>

<p class="p1">（对题解有疑问的不予回答，毕竟自己想才有乐趣）</p>

<p>-----------------------------华丽丽的分割线-----------------------------</p>

<p><span class="marker" style="color:red"><strong>鉴于题貌似出难了，大家没有什么积极性，现决定对比赛前5名发放奖品。（如有并列，并列者奖品挑选先挑先定，并列占名额，比如2个并列第一，3个并列第二，就给这五个人发奖，第三无奖）</strong></span></p>

<p><span class="marker" style="color:red"><strong>按排名先后进行奖品选择，排名越高，选项越多</strong></span></p>

<p><span class="marker" style="color:red"><strong>获奖者请于比赛结束后联系adamyi （email:adamyi@live.com qq:734806510 ）</strong></span></p>

<p>奖品：</p>

<p>1.一盒黑色中性笔</p>

<p>2.一盒笔记本</p>

<p>3.《ACM国际大学生程序设计竞赛：算法与实现》</p>

<p>4.人民币奖金30元（支付宝、paypal等）</p>

<p>5.独家纪念版FLS照片（限量版，全球唯一）</p>

<p>-----------------------------华丽丽的分割线-----------------------------</p>

<center>
<h2>EAJUDGE人物之FLS杯</h2>
</center>

<p style="color: red;">本次比赛包含7道题目，5道传统类型题目，1道开放式题目，1道AI对抗类题目。</p>

<p>传统型题目包括：两道数学题，三道算法题；</p>

<p>开放式题目为一道语义识别类题目；对抗式题目类似于NOI团体对抗赛。</p>

<p style="color: red;">比赛时间为1天，建议同学们选择任意3~4个小时的时间完成传统题目，其它时间可继续挑战（乱搞）AI试题。</p>

<p><b>命题：adamyi</b></p>

<p>审核：jx(j1x1ng)，FLS(feng_lingsong)，tmw(lolicon_tmw)</p>

<p>承办：Contest Hunter</p>

<p>欢迎同学们参加！</p>

<p>-----------------------------华丽丽的分割线-----------------------------</p>

<p>NOIp吧各种资讯答疑贴链接<a href="http://tieba.baidu.com/p/3089086145"><strong>戳这里</strong></a></p>

