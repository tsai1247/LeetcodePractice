def getKey(key: str):
    items = key.split('/')
    for i in items[::-1]:
        if i != '' and i[0] != '?':
            ret = i.split('-')
            for j in range(len(ret)):
                if len(ret[j]) > 0:
                    firstchar: str = ret[j][0]
                    remaining: str = ret[j][1:]
                    ret[j] = f'{firstchar.upper()}{remaining}'
            return ' '.join(ret)

def getURL(key: str):
    key = getKey(key)
    
    key = key.lower().replace(' ', '-')
    return f'https://leetcode.com/problems/{key}/'

url: str = input('Give me your url: ')
# url = 'https://leetcode.com/problems/maximum-subarray/'
url = getURL(url)


from os import path
import os
from typing import List, Tuple
import chromedriver_autoinstaller
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.remote.webelement import WebElement
from selenium.common.exceptions import TimeoutException

def find_element(by: str = By.ID, value: Tuple[str, None] = None, timeout: float = 10) -> WebElement:
    return WebDriverWait(driver, timeout).until(
        EC.presence_of_element_located((by, value))
    )

def find_elements(by: str = By.ID, value: Tuple[str, None] = None, timeout: float = 10) -> List[WebElement]:
    return WebDriverWait(driver, timeout).until(
        EC.presence_of_all_elements_located((by, value))
    )

chromedriver_autoinstaller.install()
chrome_options = Options()
chrome_options.headless = True
chrome_options.add_argument('log-level=2')

driver = webdriver.Chrome(options=chrome_options)
driver.maximize_window()

driver.get(url)

problem_num, title = find_element(By.XPATH, '//div[@class="h-full"]/span').text.split('.')
difficulty_tag = find_element(By.CLASS_NAME, 'mt-3').find_element(By.TAG_NAME, 'div').text
function_template = find_element(By.CLASS_NAME, 'view-lines').text[:-3]
function_name = function_template.split('public:\n')[1].split('(')[0].split(' ')[-1]

problems = find_element(By.CLASS_NAME, '_1l1MA').text.split('\n')
for i in range(len(problems)):
    if 'Example' in problems[i]:
        problems[i] = f'{problems[i].strip()}'
        break

for j in range(i+1, len(problems)):
    if 'Example' in problems[j] or 'Constraints' in problems[j] or 'Follow' in problems[j]:
        problems[j] = f'\n{problems[j].strip()}'
    else:
        problems[j] = f'\t{problems[j].strip()}'

question = ''.join(problems[:i])
example_and_followup = '\n'.join(problems[i:])

template = ''.join(open('template.cpp.template', 'r', encoding='utf-8').readlines()).split('{}')
data_inserted = [problem_num, difficulty_tag, question, example_and_followup, function_template, function_name]
result = []
assert(len(data_inserted) + 1 == len(template))
for i in range(len(data_inserted)):
    result.append(template[i])
    result.append(data_inserted[i])

result.append(template[-1])

foldername = f'{problem_num.zfill(6)}-{title}'

if not path.exists(foldername):
    os.mkdir(foldername)
open(f'{foldername}/Solution.cpp', 'w', encoding='utf-8').writelines(result)