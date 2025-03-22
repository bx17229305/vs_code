package com.bx.test01.common;

import lombok.Data;

@Data
public class Result<T>
{
    private Integer code;
    private String message;
    private T data;

    public static <T> Result<T> success(T data)
    {
        Result<T> result = new Result<>();
        result.setCode(ResultCode.SUCCESS.getCode());
        result.setMessage(ResultCode.SUCCESS.getMessage());
        result.setData(data);
        return result;
    }

    public static <T> Result<T> error(String message)
    {
        Result<T> result = new Result<>();
        result.setCode(ResultCode.FAILED.getCode());
        result.setMessage(message);
        return result;
    }

    public static <T> Result<T> error(ResultCode resultCode)
    {
        Result<T> result = new Result<>();
        result.setCode(resultCode.getCode());
        result.setMessage(resultCode.getMessage());
        return result;
    }

    public static <T> Result<T> error(ResultCode resultCode, String message)
    {
        Result<T> result = new Result<>();
        result.setCode(resultCode.getCode());
        result.setMessage(message);
        return result;
    }
} 