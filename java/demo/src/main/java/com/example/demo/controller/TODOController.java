package com.example.demo.controller;

import com.example.demo.model.TODO;
import com.example.demo.service.TODOService;
import lombok.AllArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@AllArgsConstructor
public class TODOController {
    private final TODOService todoService;


    @GetMapping("/")
    public List<TODO> getTODOList(){
        return todoService.getList();
    }

    @PostMapping("/create-todo")
    public TODO createTodo(@RequestBody String task){
        return todoService.create(task);
    }
}
