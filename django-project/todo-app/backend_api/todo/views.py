from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.response import Response
from .models import Todo
from .serializers import TodoSerializer

# Create your views here.
@api_view(['GET'])
def getOverview(request):
  urls = {
    'List':"/tasks-list/",
    'Detailed View':"/task/<str:pk>/",
    'Create':"/task-create/",
    'Update':"/task-update/<str:pk>/",
    'Delete':"/task-delete/<str:pk>/"
  }
  return Response(urls)


@api_view(['GET'])
def getList(request):
  data = Todo.objects.all()
  serializer = TodoSerializer(data, many=True)
  return Response("hey")
  
