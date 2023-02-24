package com.example.demo.model;

import lombok.Data;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;
@Data
@Document("todo")
public class TODO {
    @Id
    private String id;
    private String task;
    public TODO(String task){
        this.task = task;
    }
}
