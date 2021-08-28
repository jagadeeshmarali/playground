from django.shortcuts import render
from rest_framework.decorators import api_view
from rest_framework.response import Response
from .models import Todo
from .serializers import TodoSerializer

# Create your views here.
@api_view(['GET'])
def getOverview(request):
  urls = {
    '/list':"get_list"
  }
  return Response(urls)
@api_view(['GET'])
def get_list(request):
  data = Todo.objects.all()
  serializer = TodoSerializer(data, many=True)
  return Response(serializer.data)
  
