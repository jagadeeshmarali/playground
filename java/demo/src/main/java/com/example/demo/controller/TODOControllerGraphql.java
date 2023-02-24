package com.example.demo.controller;

import com.example.demo.model.TODO;
import com.example.demo.service.TODOService;
import lombok.AllArgsConstructor;
import org.springframework.graphql.data.method.annotation.Argument;
import org.springframework.graphql.data.method.annotation.SchemaMapping;
import org.springframework.stereotype.Controller;

@Controller
@AllArgsConstructor
public class TODOControllerGraphql {
    TODOService todoService;
    @SchemaMapping(typeName = "Mutation", field = "addTask")
    public TODO createTask(@Argument String task){

        return todoService.create(task);
    }

}
