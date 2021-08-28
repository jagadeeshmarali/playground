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
    'Detailed View':"/task/<str:id>/",
    'Create':"/task-create/",
    'Update':"/task-update/<str:id>/",
    'Delete':"/task-delete/<str:id>/"
  }
  return Response(urls)


@api_view(['GET'])
def getList(request):
  data = Todo.objects.all()
  serializer = TodoSerializer(data, many=True)
  return Response(serializer.data)

@api_view(['GET'])
def getTask(request,id):
  data = Todo.objects.get(id=id)
  serializer = TodoSerializer(data, many=False)
  return Response(serializer.data)
  
@api_view(['POST'])
def createTask(request):
  serializer = TodoSerializer(data=request.data)
  if serializer.is_valid():
    serializer.save()
  return Response(serializer.data)

@api_view(['POST'])
def updateTask(request,id):
  data = Todo.objects.get(id=id)
  serializer = TodoSerializer(instance=data, data=request.data)
  if serializer.is_valid():
    serializer.save()
  return Response(serializer.data)

@api_view(['DELETE'])
def deleteTask(request,id):
  Todo.objects.get(id=id).delete()
  return Response("Deleted Successfuly")