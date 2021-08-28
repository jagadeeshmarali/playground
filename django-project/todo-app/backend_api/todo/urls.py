from django.conf.urls import url
from todo import views

urlpatterns=[
  url('',views.getOverview),
  url('todo/',views.get_list)
]