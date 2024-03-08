Assignment 4: Weather Forecast

完成一些天气预报相关的计算

1. 完成华氏度的转换，这里需要注意使用concept，它可以方便的实现谓语的功能

   ```c++
   template<typename T>
   requires std::is_arithmetic_v<T> // concept，出现于C++20，用于保证T是数字类型
   double convert_f_to_c(T temp)
   {
       return static_cast<double>(temp - 32) * 5 / 9;
   }
   ```

2. get_forecast函数

   这里我想难懂的内容是fn的作用。fn的作用实际上是一个函数，根据具体的需求传递不同的函数给 `get_forecast` 函数，以实现不同的统计功能。例如，如果用户想获取每天的最大温度，他们可以传递一个函数，该函数返回给定一天温度读数的最大值。如果用户想要平均温度，他们可以传递一个函数，该函数返回给定一天温度读数的平均值。而fn就是这个函数。

   ```c++
   template<typename Function>
   std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn)
   {
       // write get_forecast here!
       std::vector<double> result;
       for (auto &weather_of_the_day: readings)
       {
           result.push_back(fn(weather_of_the_day));
       }
       return result;
   }
   ```

   这里我使用了匿名函数和stl来实现

   ```c++
   // Find the maximum temperature for each day and output to output.txt
   // 使用匿名函数和stl中的函数来完成
   auto maximum = get_forecast(readings,
                               [](const std::vector<int> &wea) -> double
                               {
                                   return *std::max_element(wea.begin(), wea.end());
                               });
   
   // Find the minimum temperature for each day and output to output.txt
   auto minimum = get_forecast(readings,
                               [](const std::vector<int> &wea) -> double
                               {
                                   return *std::min_element(wea.begin(), wea.end());
                               });
   
   // Find the average temperature for each day and output to output.txt
   auto average = get_forecast(readings,
                               [](const std::vector<int> &wea) -> double
                               {
                                   return std::accumulate(wea.begin(), wea.end(), double(0)) /
                                          static_cast<double>(wea.size());
                               });
   ```

