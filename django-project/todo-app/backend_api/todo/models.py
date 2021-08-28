from django.db import models

# Create your models here.

class Todo(models.Model):
  task = models.TextField(default='')
  status = models.BooleanField(default=True)
  created_at = models.DateTimeField(auto_now_add=True)
  updated_at = models.DateTimeField(auto_now=True)
