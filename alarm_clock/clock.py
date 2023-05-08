# 实现闹钟功能

from datetime import datetime
import time
import pygame


# 设置闹钟时间,不停获取系统当前时间,当闹钟时间==系统时间播放闹铃1分钟

def play_mp3(mp3_path: str):
    """
    播放1分钟音乐
    :param mp3_path: 音乐资源路径
    :return: 无返回
    """
    # 初始化
    pygame.init()
    # 加载音乐
    pygame.mixer.music.load(mp3_path)
    # 播放音乐
    pygame.mixer_music.play()
    # 设置播放1分钟
    time.sleep(300)
    # 播放结束,关闭音乐
    print("响铃结束!")
    pygame.mixer_music.stop()


# 输入闹钟时间
alarm_time = input("enter the alarm time(HH:MM):")
while True:
    # 获取当前系统时间并截取时间片段
    system_time = str(datetime.now())[11:16]
    if system_time == alarm_time:
        # 响铃
        play_mp3("千千阙歌.mp3")
