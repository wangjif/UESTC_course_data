# RateMySupervisor
永久免费开源的导师评价数据、数据爬虫、无需编程基础的展示网页以及新信息补充平台

# 如果你对编程没有了解、只想检索数据
请直接下载文件，打开`html/index.html`，我写了一个简单的UI方便检索。由于调用了`bootstrap`和`jquery`，所以打开的时候最好保持网络连接（不打开也行啦，就是UI可能有点乱）。

# 获取原始数据
`data`目录下储存了原始数据，其中：
- `urfire.json`是从[导师推荐网](https://www.urfire.com/) 获取的原始数据，该网站目前正常运作，各位也可以前往支持。**本平台开源存储数据以备各种你懂得的不可抗力因素**。
- `comments_data.json`是将数据转换为如下格式的`json`数据
```
[
  {
    "school_cate": "", 
    "university": "", 
    "department": "", 
    "supervisor": "", 
    "rate": 0, 
    "description": ""
  }
]
```

# 爬虫工具
`src/urfire.py`是[导师推荐网](https://www.urfire.com/)的爬虫工具，并包含了一个并行爬取的实例。另有将原始格式转换为上述`comments_data.json`格式的函数。

# UI工具
`html/index.html`是使用`bootstrap`和`jquery`完成的简易的检索页面。数据存储在`html/data.js`中，由`src/html_render.py`通过`comments_data.json`生成。

# 新的数据
我会不定期继续爬取其他数据，有数据的地方也烦请告知。  
另外，朋友们也可以在本平台撰写评价，请前往这条issue：[在本issue下补充导师评价信息](https://github.com/kgco/RateMySupervisor/issues/1)，发帖请使用如下格式，方便爬虫爬取：
>学校类型：985/211/研究机构/其他/(海外院校请用英文直接填写国家名称，如：Japan)
>学校名称：示例：清化大学/Cambridge University  
>院系：示例：化学化工学院/无  
>导师姓名：示例：王五  
>评分：(1-5分制，乐意的话可以填写小数，如：4.8)  
>评价：示例：对学生很好，尽职尽责  
我也会不定期爬取issue数据添加进来。

**祝各位都能有一个顺利美好的研究生生活。**
