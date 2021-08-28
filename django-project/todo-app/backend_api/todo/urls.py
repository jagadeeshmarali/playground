from django.urls import path
from todo import views

urlpatterns=[
  path('',views.getOverview,name="OverView"),
  path('tasks-list/',views.getList,name="List"),
  
]