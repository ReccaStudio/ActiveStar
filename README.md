ActiveStar
==========

暂时有bug，用于朋友讨论，请先咨询敬哲455786463@qq.com




1、懒人路径，我把整个文件夹共享了，有下面的全部文件：链接：http://pan.baidu.com/s/1ntjzAdV 密码：p3zf

下面的有些步骤可以并发，除了5对前面有依赖之外。

2、下载cocos2d-x 3.2 版本并解压，不需要安装：链接：http://pan.baidu.com/s/1dD8Iv2x 密码：d4zl 解压路径比如：D:/coco2d-x-3.2
3、下载python 2.7.x，不要安装3.x，不兼容。如果使用mac或者linux，你比我熟，这里主要按照win环境。链接：http://pan.baidu.com/s/1pJNrhnt 密码：3t4x。在win环境变量中增加python工具的安装路径：如D:/python2.7.6
4、tiledMap，地图编辑器，可能debug状态对应屏幕或者编辑地图用，或理解2.5D地图布局。链接：http://pan.baidu.com/s/1bnwBl8r 密码：24ji 布局原理如下： 可选安装

                    
---------------------------------------------------------------------
|              Col:0   (0,0)     Row:0         |       |
|                  (0,1)   (1,0)                 |
|                     (1,1)                     |
|                                             |
|                                             |
Col:max |                                             |row:Max
|                                             |
|                                             |
|                                             |
---------------------------------------------------------------------
                   Row:max,Col:max
5、进入安装目录D:/coco2d-x-3.2/，运行setup.py，此时已经完成cocos的环境配置。由于项目共享在git上，下载回来的。Lib/a/so等都是不在版本管理中的，所以需要一个其他工程的库借用一下。在命令窗口中输入：cocos new projectName -l cpp -p com.whatevet.xxx [-d projPath] 后面中括号意思是可选。
6、Git项目路径：https://github.com/wjingzhe/ActiveStar 如果不参与开发话，可以直接点右下角的download下载即可，之后解压。大家兴趣参与开发的话，我们进入组织提交申请即可：https://github.com/ReccaStudio
7、把5中项目的cocos2d文件夹复制到6的相同文件夹中，目前0.0.1版可以直接替换。以后可能需要跳过冲突文件。打开vs2012以上的IDE均可运行工程。Linux和mac的环境没有完全兼容，以后会注意意mac的路径问题，所以会要求项目添加文件是保持路径的模式。
8、因为大家的目标是解决A*算法遇到技术难点，暂时不要纠结android打包的环境配置，需要的话联系我代打个演示包——win32或者mac环境就行了。


项目介绍：1、墙角的耗散值问题未处理 2：使用了某些魔法数：如地图每个格子64宽*32高，其余10等值主要来自cocos2d-x权威指南中 3、屏幕坐标转化为Map局部坐标使用了魔法数和存在累积性误差。我未能理解原作者的坐标换算公式（魔法数值我怎么猜得出他的公式），之后考虑换成向量投影的公式、演示的demo存在一个累积性位置偏移错误，导致获取到正确的起始点和结束点，但是运行时位置出现混乱。明确：当前算法寻路路径结果是正确。4、寻路执行时的碰撞预探测和检测、路径修正未完成，路径圆滑未完成。5、排序简单处理，使用了冒泡。。因为当时想法出错了，导致效率反而是低的，目前仍未修改为heap插入。

至于我做了什么：1、3.0的代码转化为3.2的可读性代码，代码风格和实现全是我的，差别很大：比如斜角的探测，未来对3D的支持都是有可能的 2、思想都是变成我的了，注释全是我的。这么说，版权是我的。过几天把mit的协议补上。3、地图是我自己编辑出来的