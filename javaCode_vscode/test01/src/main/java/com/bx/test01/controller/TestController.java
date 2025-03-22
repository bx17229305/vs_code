package com.bx.test01.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.bx.test01.model.User;
import com.bx.test01.common.Result;

import jakarta.servlet.http.HttpSession;

import org.springframework.web.bind.annotation.RequestParam;

@RestController @RequestMapping("/api")
public class TestController
{
    @GetMapping("/test")
    public Result<String> test()
    {
        return Result.success("Hello World");
    }

    @GetMapping("/test2")
    public Result<String> test2(User user)
    {
        System.out.println(user.getName());
        System.out.println(user.getAge());
        return Result.success("Hello World");
    }

    @GetMapping("test3")
    public Result<String> setSession(HttpSession session)
    {
        session.setAttribute("name", "zhansan");
        return Result.success("ok");
    }

    @GetMapping("test4")
    public Result<String> getSession(HttpSession session)
    {
        System.out.println(session.getAttribute("name"));
        System.out.println(session.getId());
        Object value = session.getAttribute("name");
        if (value == null) {
            return Result.error("Session value not found");
        }
        return Result.success(value.toString());
    }

}
