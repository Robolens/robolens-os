# RobolensOS 

In recent years, there always has been some arguments about how _wearable_ tech may violate our digital freedoms or privacy. In past 3 years, due to the progress of technology, movies including wearable tech (such as _Spider-Man: Far From Home_ or any other Marvel movie.) and also COVID-19 pandemic, wearable technology became more and more important to the humankind.

In early 2021, [Apple](http://apple.com/watch) introduced the new version of Apple Watch, which had some cool stuff for the current pandemic situation. For example, a SpO2 (blood oxygen saturation) sensor or a feature which helps you wash your hands long enough to get rid of all the contamination you might have received from a public place.

In a short time, most of wearable gadgets included these features and people tried to have one of them at least. I was no exception. I got myself a _Xiaomi Mi Band 5_ in February 2021. It was one of the coolest gadgets I've ever had. But it still has problems I said above. I can't see what it does with my data. 

After watching Avengers, Spider-Man and some other Sci-Fi movies, I decided to make my own _Augmented Reality_ glasses, but with one big difference. I wanted it to be completely open source. This is why I started investigation and found my suitable hardware parts, and currently work on this simple OS for the project.

## Hardware Specifications 

* __Processing Unit__: NodeMCU ESP8266 (Arduino Compatible)
* __Display__: 128x32 Blue OLED Screen

## Software

This version of operating system is written in Arduino, which is a C++ dialect. The list here will be updated with changes made to the OS.

* __0.0.1__: This version connects to WiFi network (needs to be hard-coded inside the OS code by you), connects to an API (which is quiet temporary) and shows date and time. Time zone and other stuff most be changed in the API (there will be an endpoint)

## To-Do 

- [ ] Making a controller application for the whole thing.
- [ ] Adding more features like weather.
- [ ] Adding notifications or health status (needs some R&D).
- [ ] Adding ability to edit credentials using a desktop app. 