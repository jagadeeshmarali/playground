#!/bin/sh

# Heroku postgres addon
export SQLALCHEMY_DATABASE_URI=${DATABASE_URL}  # 1

export APP_MODULE=${APP_MODULE-main:app}
export HOST=${HOST:-0.0.0.0}
export PORT=${PORT:-8001}  # 3


# run gunicorn
gunicorn --bind $HOST:$PORT "$APP_MODULE" -k uvicorn.workers.UvicornWorker  # 5