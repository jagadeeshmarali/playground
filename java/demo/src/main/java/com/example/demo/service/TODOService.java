package com.example.demo.service;

import com.example.demo.model.TODO;
import com.example.demo.repository.TODORepo;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
@AllArgsConstructor
public class TODOService {
    private final TODORepo todoRepo;
    public List<TODO> getList(){
        return todoRepo.findAll();
    }

    public TODO create(String task){
        return todoRepo.save(new TODO(task));
    }
}
