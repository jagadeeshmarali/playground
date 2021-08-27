from django.shortcuts import render
from django.http import HttpResponse

def home(request):
  return HttpResponse("Hey am in home")

def products(request):
  return HttpResponse("Hey am in products page")

def customers(request):
  return HttpResponse("Hey am in customers page")
