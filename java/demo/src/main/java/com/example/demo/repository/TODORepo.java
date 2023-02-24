package com.example.demo.repository;

import com.example.demo.model.TODO;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;

import java.util.List;

public interface TODORepo extends MongoRepository<TODO, String>{

//    @Query("{id:'?0'}")
//    findById(String id );

//    @Query(fields="{'id' : 1, 'task' : 1}")
//    List<TODO> findAll();
//
//    public long count();

}