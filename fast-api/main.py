from fastapi import FastAPI,Depends
from fastapi.middleware.cors import CORSMiddleware
from db.db import get_db
from bson.objectid import ObjectId
from models.todo import Todo

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


@app.get("/")
def root():
    return {"message": "Hello World"}

@app.get("/api/todo",response_model=Todo)
async def get_todo(db=Depends(get_db)):
    data = await db.todo.find()
    result: Todo = Todo(**data)
    return result

@app.get("/api/todo/{todo_id}",response_model=Todo)
async def get_todo(todo_id: str,db=Depends(get_db)):
    data = await db.todo.find_one({"_id": ObjectId(todo_id)})
    result: Todo = Todo(**data)
    return result

@app.post("/api/todo")
async def create_todo(db=Depends(get_db),payload:Todo=None):
    result  = await db.todo.insert_one(payload.dict())
    return {"message": "Todo created successfully", "todo_id": str(result.inserted_id)}

@app.put("/api/todo/{todo_id}")
async def update_todo(todo_id: str,db=Depends(get_db),payload:Todo=None):
    result  = db.todo.update_one({"_id": ObjectId(todo_id)}, {"$set": payload.dict()})
    return {"message": "Todo updated successfully", "todo_id": str(result.inserted_id)}

@app.delete("/api/todo/{todo_id}")
async def delete_todo(todo_id: str,db=Depends(get_db)):
    result = db.todo.delete_one({"_id": ObjectId(todo_id)})
    return {"message": "Todo deleted successfully", "todo_id": str(result.inserted_id)}