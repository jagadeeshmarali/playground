import motor.motor_asyncio
import os

def get_db():
  client = motor.motor_asyncio.AsyncIOMotorClient(os.environ["MONGO_URL"], serverSelectionTimeoutMS=5000)
  return client[os.environ["MONGO_DB_NAME"]]