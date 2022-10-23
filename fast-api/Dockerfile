FROM python:3.8
WORKDIR /code
COPY requirements.txt /code/
RUN pip install -r requirements.txt
COPY . /code/
# EXPOSE 8000
RUN chmod +x run.sh
ENTRYPOINT ["/bin/bash", "-c" ,"./run.sh"]