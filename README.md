ActiveStar
==========
已封档，详情留意ProjectPlan项目计划.md相关
暂时有bug（因为累积性偏移Hero在特定情况下会表演穿墙术），用于朋友讨论和协同开发试错，请先咨询敬哲455786463@qq.com

项目介绍：
1、墙角的耗散值问题未处理 
2：使用了某些魔法数：如地图每个格子64宽*32高，其余10等值主要来自cocos2d-x权威指南中 
3、屏幕坐标转化为Map局部坐标使用了魔法数和存在累积性误差。我未能完全理解原作者的坐标换算公式（魔法数值我怎么猜得出他的公式）；所以部分改用自己的换算。之后考虑换成向量投影的公式、演示的demo存在一个累积性位置偏移错误，导致获取到正确的精灵在场景中的正确起始点和结束点（可能是之前我把Actor和Scene的坐标换算关系弄错了，暂时没去确认）。
明确：当前算法寻路路径结果是正确，因为我已经确认了寻路计算结果是正确，而执行寻路逻辑才有累计性更新错误的
4、寻路执行时的碰撞预探测和检测、路径修正未完成，路径圆滑未完成。
5、排序已修改为heap插入（其实很早前就完成了，忘记修改项目介绍，失礼了）

1、配置文档：《Proj_Env_Setup》
2、计划和工作安排：《ProjectPlan项目计划》（完成了计划内容没在版本中更新，是因为没打版本tag）
3、版本说明：《VersionedLog版本更新说明》
4、修改文件的神之子们，记得用神之手顺便添加当前文件的协议文件，参照cocos引擎的mit。只接受mit协议！！


为保证参与开发的各位可将此项目运用于小型项目，只支持非上班时间书写的代码提交。要注意：
1、周六加班时间也不要编写和提交代码
2、带薪假期也不行。比如节假日等之类
3、周一到周五晚上最好也不要提交代码，建议计划实现完全在周末实现，这样才能升职加薪:)


项目参与人员：
Jingz蓝玉：455786463 时间：2014.12.17



大家只要实质参与开发或参与讨论就自行添加，讨论群：387193878
