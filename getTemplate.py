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
    def find_once(timeout = timeout):
        return WebDriverWait(driver, timeout).until(
            EC.presence_of_element_located((by, value))
        )

    try:
        return find_once(timeout/4)
    except:
        print(f'find_element({by}, {value}) not found. Program will try again...')

    ret = find_once(timeout / 4 * 3)
    print(f'element found.')
    return ret

def find_elements(by: str = By.ID, value: Tuple[str, None] = None, timeout: float = 10) -> List[WebElement]:
    def find_once(timeout = timeout):
        return WebDriverWait(driver, timeout).until(
            EC.presence_of_all_elements_located((by, value))
        )

    try:
        return find_once(timeout/4)
    except:
        print(f'find_elements({by}, {value}) not found. Program will try again...')

    ret = find_once(timeout / 4 * 3)
    print(f'element found.')
    return ret


    

chromedriver_autoinstaller.install()
chrome_options = Options()
chrome_options.headless = True
chrome_options.add_argument('log-level=2')

driver = webdriver.Chrome(options=chrome_options)
driver.maximize_window()

while True:
    try:
        url: str = input('Give me your url: ')
    except EOFError:
        print('Receive EOF.')
        break
    except KeyboardInterrupt:
        print('Receive interrupt')
        break

    try:
        url = getURL(url)

        driver.get(url)

        problem_num, title = find_element(By.XPATH, '//div[@class="h-full"]/span').text.split('.')
        difficulty_tag = find_element(By.CLASS_NAME, 'mt-3').find_element(By.TAG_NAME, 'div').text
        function_template = find_element(By.CLASS_NAME, 'view-lines').text[:-3]
        function_name = function_template.split('public:\n')[1].split('(')[0].split(' ')[-1]

        problems = find_element(By.CLASS_NAME, '_1l1MA').text.split('\n')
        for i in range(len(problems)):
            if 'Example' in problems[i]:
                problems[i] = f'* {problems[i].strip()}'
                break
        question = '```\n' + '\n'.join(problems[:i]) + '\n```'

        content_tab_num = 2
        for j in range(i+1, len(problems)):
            if 'Example ' in problems[j] or 'Constraints:' in problems[j] or 'Follow up:' in problems[j]:
                problems[j] = f'\n* {problems[j].strip()}'
                if 'Constraints:' in problems[j]:
                    content_tab_num = 0
                else:
                    content_tab_num = 2

            elif 'Input:' in problems[j] or 'Output:' in problems[j] or 'Explanation:' in problems[j]:
                problems[j] = f'\t* {problems[j].strip()}'
            else:   # content
                problems[j] = ('\t' * content_tab_num) + f'* {problems[j].strip()}'

        examples = ''
        constraints = None
        followup = ''

        for j in range(i+1, len(problems)):
            if 'Constraints:' in problems[j]:
                examples = '\n'.join(problems[i:j])
                i = j+1
            elif 'Follow' in problems[j] and 'up:' in problems[j]:
                constraints = '\n'.join(problems[i:j])
                i = j
        if constraints is None:
            constraints = '\n'.join(problems[i:])
        else:
            followup = '\n'.join(problems[i:])
        i = j+1

        foldername = f'{problem_num.zfill(6)}-{title}'
        if not path.exists(foldername):
            os.mkdir(foldername)

        def fill_template(template_filename: str, data_insertedd: List[str]) -> List[str]:
            content = []
            template = ''.join(open(template_filename, 'r', encoding='utf-8').readlines()).split('{}')
            assert(len(data_insertedd) + 1 == len(template))
            for i in range(len(data_insertedd)):
                content.append(template[i])
                content.append(data_insertedd[i])
            content.append(template[-1])
            
            return content

        md_data_inserted = [problem_num, difficulty_tag, question, 
                            examples, constraints, followup]
        cpp_data_inserted = [function_template, function_name]

        cpp_content = fill_template('template.cpp.template', cpp_data_inserted)
        md_content = fill_template('template.md.template', md_data_inserted)

        open(f'{foldername}/Solution.cpp', 'w', encoding='utf-8').writelines(cpp_content)
        open(f'{foldername}/Problem.md', 'w', encoding='utf-8').writelines(md_content)

        print('\ntemplate grenerated.')
    except:
        print('template generation failed.')