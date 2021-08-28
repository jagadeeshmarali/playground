from django.urls import path
from todo import views

urlpatterns=[
  path('',views.getOverview,name="OverView"),
  path('tasks-list/',views.getList,name="List"),
  path('task/<str:id>/',views.getTask,name="Get Task"),
  path('task-create/',views.createTask,name="Create Task"),
  path('task-update/<str:id>/',views.updateTask,name="Update Task"),
  path('task-delete/<str:id>/',views.deleteTask,name="Delete Task"),
  
]