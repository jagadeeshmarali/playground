import subprocess
import requests

# Define the stream URL
stream_url = "https://0ijq1i6sp1.execute-api.us-east-1.amazonaws.com/dev/stream"
c= []
# print(request.get("stream_url"))


for i in range(100):
  response = subprocess.run(["curl", "-s", stream_url], capture_output=True, text=True).stdout
  response = response.replace("\n", "")
  c.append(response)
  

# Execute curl command to get the response


# Extract unique characters from the response
unique_chars = set(c)

# Print the unique characters
print("Unique characters:", unique_chars)
