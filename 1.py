import urlib2
response=urlib2.urlopen("www.baidu.com")
mm=response.read()
print mm
