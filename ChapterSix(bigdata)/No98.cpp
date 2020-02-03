/*
【名称】找到100亿个URL中重复的URL以及搜索词汇的TopK问题
【题目】有一个包含100亿个URL大文件，假设每个URL占用64B,请找出其中所有
重复的URL。
【补充题目】某搜索公司一天的用户搜索词汇是海量的，请设计一种求出每天最热top100词汇的可行办法
【难度】士
*/

/*
原问题：将100亿字节的大文件通过哈希函数分配到1000台机器上（或小文件），然后每一台机器分别统计
分给自己的URL中是否有重复的URL，同是哈希函数的性质决定同一个URL不可能分给不同的机器（或文件），
对每一个机器（或文件）再利用哈希表遍历，找出重复的URL,或者进行排序，然后看是否有重复的URL出现。

补充问题：哈希分流+推结构+外排序
*/