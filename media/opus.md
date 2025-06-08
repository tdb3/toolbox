## Opus codec

### Using ffmpeg to encode to opus

Convert to 16Khz @ around 24kbps
```
ffmpeg -i voice-sample.wav -ar 16000 -c:a libopus -b:a 24k voice.opus
```


