import httpx
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.edge.service import Service
from selenium.webdriver.edge.options import Options

url = 'https://www.beqege.cc/16747/223291.html'
HEADERS = {
    'User-Agent' : 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36 Edg/128.0.0.0'
}


edge_options = Options()
edge_options.add_argument("--headless")

service = Service('/Users/meinv/Downloads/edgedriver_mac64_m1/msedgedriver')

driver = webdriver.Edge(service=service, options= edge_options)

driver.get(url)

page_source = driver.page_source
print(page_source)

driver.quit()