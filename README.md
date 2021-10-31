# 算法与数据结构设计
## 题目4B
> Copyright 2021 HuaCL
## 题目4：汽车牌照模拟查询系统
在汽车数据的信息模型中，汽车牌照是具有结构特点的一类关键字。汽车牌照是字母和数字混编的，例如：苏A0B7238。利用查找和排序算法，实现省内汽车牌照的快速查找。
1. 需要设置普通用户、超级管理员不同角色，不同角色登录后的权限各不相同，普通用户可以进行查询；超级管理员有对汽车牌照增加、删除和修改的权限。
2. 汽车牌照信息应包含号码、车辆、车主等相应信息，信息保存在文本文件中。
3. 对汽车牌照进行排序，并实现顺序查找功能。
4. 采用对半查找汽车牌照查询出所对应的车辆及车主信息。
5. 可以按城市建立索引表，进行分块索引查找。
6. 界面美观，交互方便

## 报告
### 数据结构设计
* 结构体plate
  * 车牌
  * 车主姓名
  * 车辆信息？？？？
  * 车主手机号