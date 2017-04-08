# valkyr
安装：
1.进入premake文件夹，premake5 vs2015或2017，在build文件夹生成项目文件，premake5.exe为alpha 11版本
2.打开vapp项目属性，链接器里把入口点mainCRTstartup删除掉（todo:premake里配置项清除掉这个）
3.项目编译顺序：valkyr为优先，其他可以随意，启动项目设为vapp