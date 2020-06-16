# Cpp-Reverse-Shell-Backdoor

<h2 style="color: #5e9ca0;"><span style="color: #000000;">*** Don't upload to VirusTotal! ***</span></h2>
<h2 style="color: #2e6c80;"><span style="color: #000000;">C++ customizable and undetectable Backdoor</span></h2>
<p><span style="color: #000000;">It works with all Microsoft Windows distributions</span></p>
<h2 style="color: #2e6c80;"><span style="color: #000000;">features included:</span></h2>
<ol style="list-style: none; font-size: 14px; line-height: 32px; font-weight: bold;">
<li style="clear: both;"><span style="color: #000000;">Hidden terminal prompt</span></li>
<li style="clear: both;"><span style="color: #000000;">Sleep/delay execution</span></li>
<li style="clear: both;"><span style="color: #000000;">Fake error prompt to distract the victim</span></li>
<li style="clear: both;"><span style="color: #000000;">Persistent Backdoor (Windows startup)</span></li>
</ol>
<h2><span style="color: #000000;">Instructions:</span></h2>
<p><span style="color: #000000;">Change IP and port with your attacker machine configuration. Then compile using:</span><strong>&nbsp;i686-w64-mingw32-gcc 0fud.cpp -o 0fud.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc</strong></p>
<p>Set and start a listener with netcat:</p>
<p>nc -lvp &lt;port&gt; // e.g. nc -lvp 443</p>
<p><strong>-- --</strong></p>
<p><strong>To avoid the code being add to AV signatures, don't upload to VirusTotal, or any other online AV (including your desktop AV. If you want to try to make a scan, turn off your internet connection or use offline AV.</strong></p>
<p><strong>-- --</strong></p>
<b>Youtube Tutorial: https://youtu.be/gSFhIbkhnuw
<p>#AppuntiDaHacker Youtube Channel</b></p>
<p></p>
Scan results:
<img src="https://github.com/wrongsid3/Cpp-Reverse-Shell-Backdoor/blob/master/defender.PNG?raw=true" alt="defender scan" width="545" height="344">
<img src="https://github.com/wrongsid3/Cpp-Reverse-Shell-Backdoor/blob/master/avg.PNG?raw=true" alt="avg scan" width="592,5" height="390">
