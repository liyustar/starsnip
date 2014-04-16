import httplib2

YOOLI = 'http://www.yooli.com/'
INVEST = 'http://www.yooli.com/invest/'
YUEXITONG = 'http://www.yooli.com/yuexitong/'


h = httplib2.Http()

resp, content = h.request(YOOLI)
resp, content = h.request(INVEST)
resp, content = h.request(YUEXITONG)
print content

