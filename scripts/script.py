import csv
import random
import datetime
import yaml

with open('config.yaml', 'r') as f:
    config = yaml.safe_load(f)

samples = config['generator']['samples']
start_date = datetime.datetime.strptime(str(config['generator']['time']['startDate']), "%Y-%m-%d")
end_date = datetime.datetime.strptime(str(config['generator']['time']['endDate']), "%Y-%m-%d")
actions = config['generator']['actions']
ip_addresses = config['generator']['ip_address']
storage = config['generator']['storage']

data = []

for i in range(samples):
    random_date = start_date + (end_date - start_date) * random.random()
    date_string = random_date.strftime("%Y-%m-%d %H:%M:%S")
    action = random.choice(actions)
    ip = random.choice(ip_addresses)
    data.append([date_string, action, ip, storage])

# write data to csv file
with open('data.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['date', 'action', 'ip_address', 'storage'])
    writer.writerows(data)

print("Data generation complete and saved to data.csv")
