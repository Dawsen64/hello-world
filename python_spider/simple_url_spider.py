#-*- codeing = utf-8 -*-
#@Time : 2021/9/18
#@Auther : zqiusen
#@File : simple_url_spider.py
#@Softwar : VSCode
#@Python-V : python3.9.6

from bs4 import BeautifulSoup # 解析网页
import re # 正则表达式
import urllib.request, urllib.error # 由url获取网页数据
import xlwt
from xlrd import open_workbook
import xlrd
import openpyxl
from xlutils.copy import copy
# import sqlite3 #进行SQLitee数据库操作
import time
import random

def main():
    baseurl = "https://5geqao.xyz/h/dongman/list_5_"
    # 1.爬取网页
    getData(baseurl)




findLink = re.compile(r"""<a href="(.*?)"><img""")
findTitle = re.compile(r"""</a><p><a href=".*?">(.*?)</a></p>""")
def getData(baseurl):
    datalist = []
    count = 0
    #动漫最大页是258
    for i in range(1,258):
        url = baseurl + f'{i}.html'
        time.sleep(random.random())
        html = askUrl(url) # 获得每一页的网页源码
        # 2.解析出网页中我需要的url
        soup = BeautifulSoup(html, "html.parser")
        # print(soup.ul)
        for pin in soup.find_all('li', 'pin'):

            title = re.findall(findTitle, str(pin))
            # print("title:", title)

            link = re.findall(findLink, str(pin))
            if (len(link[0])) >= 3:
                link = "https://5geqao.xyz" + link[0]
                tmp = []
                tmp.append(link)
                print(title + tmp)
                count += 1
                datalist.append(title + tmp)
        
        # 3.保存数据
        savepath = "5gmp4.xls"
        saveData(datalist, savepath, i)
        datalist = []
        print(f"完成第{i}页。")   



    print(f"爬取结束,共{count}个")

def askUrl(url):
    head = {  #模拟浏览器头部信息，向豆瓣服务器发送消息
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36 Edg/93.0.961.47"
    }
    request = urllib.request.Request(url,headers=head)
    html = ""
    try:
        response = urllib.request.urlopen(request)
        html = response.read().decode("utf-8")
        # print(html)
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)
    return html

def saveData(datalist, savepath, count):
    print("Save......")
    if count == 1:
        book = xlwt.Workbook(encoding="utf-8", style_compression=0)
        sheet = book.add_sheet("5gurl",cell_overwrite_ok=True)
        col = ("title", "url")
        for i in range(0, 2):
            sheet.write(0, i, col[i])
        book.save(savepath)
    else:
        workbook = xlrd.open_workbook(savepath)  # 打开工作簿
        # sheets = workbook.sheet_names()  # 获取工作簿里的所有表格
        worksheet = workbook.sheet_by_name("5gurl")  # 获取工作簿中所有表格中的第一个表格
        rows_old = worksheet.nrows  # 获取表格中已存在的数据的行数
        new_workbook = copy(workbook)  # 将xlrd对象拷贝转化为xlwt对象
        new_worksheet = new_workbook.get_sheet(0)  # 获取转化后工作簿中的第一个表格
        
        for i in range(0, 15):
            for j in range(2):
                new_worksheet.write(i+rows_old+1, j, datalist[i][j])  # 追加写入数据，注意从 i+rows_old 行开始
        
        new_workbook.save(savepath)

        # book = open_workbook(savepath)
        # sheet = book.sheet_by_index(0)
        # # 15*258 = 
        # count -= 1
        # for i in range(count*15, count*15+15):
        #     num = 0
        #     data = datalist[num]    
        #     num += 1
        #     for j in range(2):
        #         sheet.write(i+1, j, data[j])
        # book.save(savepath)


def has_class_but_no_id(tag):
    return tag.has_attr('class') and not tag.has_attr('id')
if __name__ == '__main__':
    main()
