from selenium import webdriver

# Set up Selenium webdriver (make sure you have chromedriver or geckodriver installed and in your PATH)
driver = webdriver.Chrome()  # or webdriver.Firefox()

# Open the webpage
driver.get("https://opencorporates.com/")  # Replace with your desired webpage URL

# Find all the <li> tags and extract the URLs
urls = []
li_tags = driver.find_elements_by_tag_name("li")
for li in li_tags:
    url = li.find_element_by_tag_name("a").get_attribute("href")
    urls.append(url)

# Save the URLs to a text file
with open("urls.txt", "w") as file:
    file.write("\n".join(urls))

# Close the webdriver
driver.quit()
