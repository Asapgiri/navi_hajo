static const char PROGMEM index_html[] = R"======(
<!DOCTYPE html>
<html lang="hu">
  <head>
    <title>Ship Project</title>
    <meta charset="UTF-8">
    <style>
      body {
        height: 700px;
        margin: 0px;
      }

      .slider {
        -webkit-appearance: none; /* WebKit */
        top: -50px;
        width: 500px;
        height: 50px;
        background: #d3d3d3;
        outline: none;
        opacity: 0.7;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider-vertical {
        direction: rtl;
        transform-origin: bottom left;
        transform: rotate(90deg);
      }

      .slider:hover {
        opacity: 1;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 50px;
        height: 75px;
        background: #04AA6D;
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 100%;
        background: #04AA6D;
        cursor: pointer;
      }

      #control_left {
        position: fixed;
        left: 0px;
        width: 50px;
        height: calc(100% - 50px);
        margin: 25px;
      }

      #control_right {
        position: fixed;
        right: 0px;
        width: 50px;
        height: calc(100% - 50px);
        margin: 25px;
      }

      #middle {
        width: calc(100% - 200px);
        height: 600px;
        margin: 75px 0px;
        left: 100px;
        position: fixed;
      }

      #topper {
        position: fixed;
        margin: 0px 25px;
      }
      #answer_container {
        position: absolute;
        bottom: 0px;
        width: 100%;
        height: 150px;
        margin: 0px;
        overflow: auto;
      }

      #datas table {
        width: 200px;
      }
      #datas th, #datas2 th, #datas3 th {
        text-align: left;
        padding-top: 15px;
        margin-bottom: 3px;
        padding-left: 10%;
        border-bottom: 1px solid black;
      }
      #datas td, #datas2 td, #datas3 td {
        width: 50%;
      }
      #datas2 th {
        padding-top: 0px;
      }

      #datas {
        position: absolute;
        float: left;
      }
      #datas2 {
        position: absolute;
        float: left;
        left: 200px;
        max-width: 600px;
        margin-top: 220px;
      }
      #datas2 table {
        float: left;
        min-width: 150px;
        margin: 10px;
      }

      #datas3 {
        position: absolute;
        right: 0px;
        min-width: 150px;
        width: calc(100% - 800px);
        height: 380px;
      }
      #datas3 table {
        width: 100%;
      }

      #buttons_div {
        position: absolute;
        margin: 25px;
        right: 0px;
        top: 0px;
      }
      #buttons_div > * {
        float: left;
        margin-right: 10px;
        border: 1px solid darkred;
        padding: 3px;
        height: 24px;
        padding-right: 7px;
        text-align: center;
      }

      .circle {
        float: left;
        position: relative;
        margin: 10px;
        width: 200px;
        height: 200px;
        -webkit-border-radius: 100px;
        -moz-border-radius: 100px;
        border-radius: 100px;
        background: transparent;
        border: 1px solid grey;
      }
      .line {
        background: black;
        height: 86px;
        width: 2px;
        margin: 50%;
        transform-origin: top left;
        transform: rotate(61deg);
      }

      .inner-text {
        position: absolute;
        background: transparent;
        margin: 75% 25%;
        width: 100px;
        text-shadow: #04AA6D;
        text-align: center;
      }

      .line-base {
        position: absolute;
        background: transparent;
        height: 100px;
        width: 1px;
        margin: 50%;
        transform-origin: top left;
        font-size: small;
      }
      .line-base div {
        position: absolute;
        bottom: 3px;
        height: 20px;
        width: 1px;
        background-color: black;
      }
      .line-base span {
        position: absolute;
        bottom: 1px;
        left: 3px;
      }
      #__0percent {
        transform: rotate(60deg);
      }
      #__0percent span {
        transform: rotate(-60deg);
      }
      #__10percent {
        transform: rotate(84deg);
      }
      #__10percent span {
        transform: rotate(-84deg);
      }
      #__20percent {
        transform: rotate(108deg);
      }
      #__20percent span {
        transform: rotate(-108deg);
      }
      #__30percent {
        transform: rotate(132deg);
      }
      #__30percent span {
        transform: rotate(-132deg);
      }
      #__40percent {
        transform: rotate(156deg);
      }
      #__40percent span {
        transform: rotate(-156deg);
      }
      #__50percent {
        transform: rotate(180deg);
      }
      #__50percent span {
        transform: rotate(-180deg);
      }
      #__60percent {
        transform: rotate(204deg);
      }
      #__60percent span {
        transform: rotate(-204deg);
      }
      #__70percent {
        transform: rotate(228deg);
      }
      #__70percent span {
        transform: rotate(-228deg);
      }
      #__80percent {
        transform: rotate(252deg);
      }
      #__80percent span {
        transform: rotate(-252deg);
      }
      #__90percent {
        transform: rotate(276deg);
      }
      #__90percent span {
        transform: rotate(-276deg);
      }
      #__100percent {
        transform: rotate(300deg);
      }
      #__100percent span {
        transform: rotate(-300deg);
      }
      #__0percent div, #__100percent div {
        height: 28px;
      }
      #__30percent div {
        height: 28px;
        background-color: red;
      }
      #__70percent div {
        height: 28px;
        background-color: red;
      }

      #__n75deg {
        transform: rotate(60deg);
      }
      #__n75deg span {
        transform: rotate(-60deg);
      }
      #__n50deg {
        transform: rotate(100deg);
      }
      #__n50deg span {
        transform: rotate(-100deg);
      }
      #__n25deg {
        transform: rotate(140deg);
      }
      #__n25deg span {
        transform: rotate(-140deg);
      }
      #__0deg {
        transform: rotate(180deg);
      }
      #__0deg span {
        transform: rotate(-180deg);
      }
      #__25deg {
        transform: rotate(220deg);
      }
      #__25deg span {
        transform: rotate(-220deg);
      }
      #__50deg {
        transform: rotate(260deg);
      }
      #__50deg span {
        transform: rotate(-260deg);
      }
      #__75deg {
        transform: rotate(300deg);
      }
      #__75deg span {
        transform: rotate(-300deg);
      }
      #__n75deg div, #__75deg div {
        height: 28px;
      }
      #__0deg div {
        height: 28px;
        background-color: red;
      }

      #clocks {
        position: absolute;
        top: 0px;
        left: 200px;
      }

      .red {
        display: block;
        float: left;
        background: red;
        width: 20px;
        height: 20px;
        margin: 0px;
        margin-right: 3px;
        border-radius: 3px;
      }
    </style>
    <script>
      var same_speed = true;
      var can_send = true;
      function sameSpeed(speed) {
        document.getElementById('speedLeft').value = speed;
        document.getElementById('speedRight').value = speed;
        document.getElementById('speedlabel_left').innerText = (.01*speed*5).toFixed(2) + 'V | ' + speed;
        document.getElementById('speedlabel_right').innerText = (.01*speed*5).toFixed(2) + 'V | ' + speed;
        if (speed >= 0) document.getElementById('speed_line').style.transform = `rotate(${60+speed*2.4}deg)`;
        else document.getElementById('speed_line').style.transform = `rotate(${60-speed*2.4}deg)`;
      }
      function setServoClock(deg) {
          document.getElementById('deg_line').style.transform = `rotate(${180+deg*1.6}deg)`;
      }
      function sendBackMotorData(motor) {
        if (can_send) {
          can_send = false;
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              log(this.response);
            }
          };
          xhttp.open("GET", `/send_data?${motor == 'left' || same_speed ? 'ls=' + document.getElementById('speedLeft').value + '&' : ''}${motor == 'right' || same_speed ? 'rs=' + document.getElementById('speedRight').value : ''}`, true);
          xhttp.send();
          setTimeout(function() {
            can_send = true;
          }, 100);
        }
      }
      function requestData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200 && this.response != "") {
            resp = JSON.parse(this.responseText);
            log(this.response, resp.t);

            switch (resp.t) {
                case 'sl':  // Ship location
                case 'g': 
                    travelledTo([resp.d.lon, resp.d.lat])
                    break;
                case 'tm':
                    document.getElementById('akku_temp').innerText = resp.d.b
                    document.getElementById('air_temp').innerText = resp.d.a
                    document.getElementById('water_temp').innerText = resp.d.w
                    break;
                case 'tr':
                    for (const [key, value] of Object.entries(resp.d.a)) {
                        document.getElementById('water_'+key).style.background = value ? 'red' : 'green'
                    }


                case 'OK.': break;

                case 'd':
                default:
                    log('Unknown/Not yet supported response type.')
                    break;
            }
          }
        };
        xhttp.open("GET", "/request_data", true);
        xhttp.send();
      }
      function log(msg) {
          answer = document.getElementById('answer') 
          const date = new Date()
          const local = date.toLocaleTimeString()
          const ms = date.getMilliseconds()
          answer.innerText += "\n[" + local + "." + date.getMilliseconds() + (ms < 100 ? ms < 10 ? '00' : '0' : '') + "]: " + msg;
          answer_container = document.getElementById('answer_container')
          answer_container.scrollTop = answer_container.scrollHeight
      }
    </script>
  </head>
  <body>
    <div id="topper"><h1>Hajó controller</h1></div>
    <div id="control_left">
      <input type="range" min="-100" max="100" value="0" orient="vertical" class="slider slider-vertical" onmouseup="can_send = true; sendBackMotorData('left');" oninput="if (!same_speed) { document.getElementById('speedlabel_left').innerText = (.01*this.value*5).toFixed(2) + 'V | ' + this.value; } else { sameSpeed(this.value); } sendBackMotorData('left');" id="speedLeft">
    </div>
    <div id="middle">
      <div id="datas">
        <table>
          <tr><th colspan="2">Sebességek</th></tr>
          <tr><td>Bal:</td><td><span id="speedlabel_left">-</span>%</td></tr>
          <tr><td>Jobb:</td><td><span id="speedlabel_right">-</span>%</td></tr>
          <tr><th colspan="2">Szenzorok</th></tr>
          <tr><td>Akku:</td><td><span id="akku_percent">-</span>% <span id="akku_charging">[merítés]</span></td></tr>
          <tr><td>Akku:</td><td><span id="akku_temp">-</span> °C</td></tr>
          <tr><td>Levegő:</td><td><span id="air_temp">-</span> °C</td></tr>
          <tr><td>Víz:</td><td><span id="water_temp">-</span> °C</td></tr>
          <tr><th colspan="2">Vízszint</th></tr>
          <tr><td>&uarr;BE<span class="red" id="water_ulf"></span></td><td>&uarr;JE<span class="red" id="water_urf"></span></td></tr>
          <tr><td>&uarr;BH<span class="red" id="water_ulb"></span></td><td>&uarr;JH<span class="red" id="water_urb"></span></td></tr>
          <tr><td>&darr;BE <span class="red" id="water_blf"></span></td><td>&darr;JE <span class="red" id="water_brf"></span></td></tr>
          <tr><td>&darr;BH <span class="red" id="water_blb"></span></td><td>&darr;JH <span class="red" id="water_brb"></span></td></tr>
        </table>
      </div>
      <div id="datas2">
        <table>
          <tr><th colspan="2">ESP-M3</th></tr>
          <tr><td>Cím:</td><td><span id="something">-</span>%</td></tr>
        </table>
        <table>
          <tr><th colspan="2">GSM</th></tr>
          <tr><td>Cím:</td><td><span id="something">-</span>%</td></tr>
        </table>
      </div>
      <div id="datas3">
        <table>
          <tr><th colspan="2">Iránytű</th></tr>
          <tr><td>Cím:</td><td><span id="something">-</span>%</td></tr>
        </table>
        <table>
          <tr><th colspan="2">GPS</th></tr>
          <tr><td>Cím:</td><td><span id="something">-</span>%</td></tr>
        </table>
      </div>

      <div id="clocks">
        <div class="circle">
          <div class="inner-text"><span>Sebesség</span></div>
          <div class="line-base" id="__0percent"><div></div></div>
          <div class="line-base" id="__10percent"><div></div><span>10</span></div>
          <div class="line-base" id="__20percent"><div></div><span>20</span></div>
          <div class="line-base" id="__30percent"><div></div><span>30</span></div>
          <div class="line-base" id="__40percent"><div></div><span>40</span></div>
          <div class="line-base" id="__50percent"><div></div><span>50</span></div>
          <div class="line-base" id="__60percent"><div></div><span>60</span></div>
          <div class="line-base" id="__70percent"><div></div><span>70</span></div>
          <div class="line-base" id="__80percent"><div></div><span>80</span></div>
          <div class="line-base" id="__90percent"><div></div><span>90</span></div>
          <div class="line-base" id="__100percent"><div><span>100</span></div></div>
          <div class="line" id="speed_line"></div>
        </div>
        <div class="circle">
          <div class="inner-text"><span>Kanyarodás</span></div>
          <div class="line-base" id="__n75deg"><div></div><span>-75&#176;</span></div>
          <div class="line-base" id="__n50deg"><div></div><span>-50&#176;</span></div>
          <div class="line-base" id="__n25deg"><div></div><span>-25&#176;</span></div>
          <div class="line-base" id="__0deg"><div></div><span>0&#176;</span></div>
          <div class="line-base" id="__25deg"><div></div><span>25&#176;</span></div>
          <div class="line-base" id="__50deg"><div></div><span>50&#176;</span></div>
          <div class="line-base" id="__75deg"><div></div><span>75&#176;</span></div>
          <div class="line" id="deg_line"></div>
        </div>
      </div>

      <div id="answer_container">
          <pre id="answer">

          </pre>
      </div>
    </div>
    <div id="buttons_div">
      <a href="auto">Autómatikus vezérlés</a>
      <div id="right_topper">
        <input id="input_sameSpeed" type="checkbox" checked="true" oninput="same_speed = this.checked;"/><label style="cursor: pointer;" onclick="if (same_speed) { document.getElementById('input_sameSpeed').checked = false; same_speed = false; } else { document.getElementById('input_sameSpeed').checked = true; same_speed = true; }">Sebesség lock</label>
      </div>
    </div>
    <div id="control_right">
      <input type="range" min="-100" max="100" value="0" orient="vertical" class="slider slider-vertical" onmouseup="can_send = true; sendBackMotorData('right');" oninput="if (!same_speed) { document.getElementById('speedlabel_right').innerText = (.01*this.value*5).toFixed(2) + 'V | ' + this.value; } else { sameSpeed(this.value); } sendBackMotorData('right');" id="speedRight">
    </div>
    <script>
      setInterval(requestData, 100);
    </script>
  </body>
</html>
)======";

static const char PROGMEM auto_html[] = R"======(
<!DOCTYPE html>
<html lang="hu">
  <head>
    <title>Ship Project</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.7.1/dist/leaflet.css"
    integrity="sha512-xodZBNTC5n17Xt2atTPuE1HxjVMSvLVW9ocqUKLsCC5CXdbqCmblAshOMAS6/keqq/sMZMZ19scR4PsZChSR7A=="
    crossorigin=""/>
    <script src="https://unpkg.com/leaflet@1.7.1/dist/leaflet.js"
   integrity="sha512-XQoYMqMTK8LvdxXYG3nZ448hOEQiglfqkJs1NOQV44cWnUrBc8PkAOcXy20w0vlaXaVUearIOBhiXZ5V3ynxwA=="
   crossorigin=""></script>
    <style>
      body {
        height: 700px;
        margin: 0px;
      }

      .slider {
        -webkit-appearance: none; /* WebKit */
        top: -50px;
        width: 500px;
        height: 50px;
        background: #d3d3d3;
        outline: none;
        opacity: 0.7;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider-vertical {
        direction: rtl;
        transform-origin: bottom left;
        transform: rotate(90deg);
      }

      .slider:hover {
        opacity: 1;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 50px;
        height: 75px;
        background: #04AA6D;
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 100%;
        background: #04AA6D;
        cursor: pointer;
      }

      #control_left {
        position: fixed;
        left: 0px;
        width: 50px;
        height: calc(100% - 50px);
        margin: 25px;
      }

      #control_right {
        position: fixed;
        right: 0px;
        width: 50px;
        height: calc(100% - 50px);
        margin: 25px;
      }

      #container {
        width: calc(100% - 50px);
        height: 600px;
        margin: 75px 0px;
        left: 25px;
        position: fixed;
      }

      #topper {
        position: fixed;
        margin: 0px 25px;
      }
      #answer_container {
        position: absolute;
        bottom: 0px;
        width: 100%;
        height: 150px;
        margin: 0px;
        overflow: auto;
      }

      #datas table {
        width: 200px;
      }
      #datas th, #datas2 th, #datas3 th {
        text-align: left;
        padding-top: 15px;
        margin-bottom: 3px;
        padding-left: 10%;
        border-bottom: 1px solid black;
      }
      #datas td, #datas2 td, #datas3 td {
        width: 50%;
      }
      #datas2 th {
        padding-top: 0px;
      }

      #datas {
        position: relative;
        float: left;
      }
      #datas2 {
        position: absolute;
        float: left;
        left: 200px;
        max-width: 600px;
        margin-top: 220px;
      }
      #datas2 table {
        float: left;
        min-width: 150px;
        margin: 10px;
      }

      #datas3 {
        position: absolute;
        right: 0px;
        min-width: 150px;
        width: calc(100% - 800px);
        height: 380px;
      }
      #datas3 table {
        width: 100%;
      }

      #buttons_div {
        position: absolute;
        margin: 25px;
        right: 0px;
        top: 0px;
      }
      #buttons_div > * {
        float: left;
        margin-right: 10px;
        border: 1px solid darkred;
        padding: 3px;
        height: 24px;
        padding-right: 7px;
        text-align: center;
      }

      .circle {
        float: left;
        position: relative;
        margin: 10px;
        width: 200px;
        height: 200px;
        -webkit-border-radius: 100px;
        -moz-border-radius: 100px;
        border-radius: 100px;
        background: transparent;
        border: 1px solid grey;
      }
      .line {
        background: black;
        height: 86px;
        width: 2px;
        margin: 50%;
        transform-origin: top left;
        transform: rotate(61deg);
      }

      .inner-text {
        position: absolute;
        background: transparent;
        margin: 75% 25%;
        width: 100px;
        text-shadow: #04AA6D;
        text-align: center;
      }

      .red {
        display: block;
        float: left;
        background: red;
        width: 20px;
        height: 20px;
        margin: 0px;
        margin-right: 3px;
        border-radius: 3px;
      }

      #map {
          height: 400px;
          position: relative;
          float: right;
          width: calc(100% - 420px);
      }
    </style>
    <script>
      var can_send = true;

      function sendBackData(data) {
        if (can_send) {
          can_send = false;
          var xhttp = new XMLHttpRequest();
          /*xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              log(this.response);
            }
          };*/
          let params = ''
          let first = true;
          Object.keys(data).forEach(key => {
              params += (first ? '' : '&') + key + '=' + data[key]
              first = false;
          })
          xhttp.open("GET", `/send_data?${params}`, true);
          xhttp.send();
          setTimeout(function() {
            can_send = true;
          }, 100);
        }
      }

      function requestData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200 && this.response != "") {
            resp = JSON.parse(this.responseText);
            log(this.response, resp.t);

            switch (resp.t) {
                case 'sl':  // Ship location
                case 'g': 
                    travelledTo([resp.d.lon, resp.d.lat])
                    document.getElementById('gps_lat').innerText = resp.d.lat
                    document.getElementById('gps_lng').innerText = resp.d.lon
                    break;
                case 'tm':
                    document.getElementById('akku_temp').innerText = resp.d.b
                    document.getElementById('air_temp').innerText = resp.d.a
                    document.getElementById('water_temp').innerText = resp.d.w
                    break;
                case 'tr':
                    for (const [key, value] of Object.entries(resp.d.a)) {
                        document.getElementById('water_'+key).style.background = value ? 'red' : 'green'
                    }
                case 'c':
                  calculate_compass(resp.d)
                  break;
                
                case 'm':
                case 'OK.': break;

                case 'd':
                default:
                    log('Unknown/Not yet supported response type.')
                    break;
            }
          }
        };
        xhttp.open("GET", "/request_data", true);
        xhttp.send();
      }

      function calculate_compass(data) {
        document.getElementById('c_degx').innerText = data.deg.toString()
        document.getElementById('c_acc').innerText = data.acc.toString()
        document.getElementById('c_velocity').innerText = data.vcc.toString()
      }

      function fastRequest(ms) {
        intervalId = setInterval(requestData, 20)
        setTimeout(() => clearInterval(intervalId), ms || 3000)
      }

      function log(msg, type = 'd') {
          answer = document.getElementById('answer') 
          const date = new Date()
          const local = date.toLocaleTimeString()
          const ms = date.getMilliseconds()
          answer.innerText += "\n[" + local + "." + date.getMilliseconds() + (ms < 100 ? ms < 10 ? '00' : '0' : '') + "]: " + msg;
          answer_container = document.getElementById('answer_container')
          answer_container.scrollTop = answer_container.scrollHeight
      }

      function getGpsRoute() {
          return {
            type: 'LineString',
              coordinates: [
                [
                    18.874940872192383,
                    47.80174061449277
                ],
                [
                    18.873138427734375,
                    47.80197122321683
                ],
                [
                    18.871421813964844,
                    47.80272069450014
                ],
                [
                    18.86953353881836,
                    47.80329720351409
                ],
                [
                    18.868074417114254,
                    47.803873706129956
                ],
                [
                    18.866701126098633,
                    47.8043925530139
                ],
                [
                    18.866701126098633,
                    47.805084340797585
                ],
                [
                    18.86730194091797,
                    47.80583376716645
                ],
                [
                    18.86824607849121,
                    47.80617965261286
                ],
                [
                    18.869447708129883,
                    47.806237299963335
                ],
                [
                    18.871421813964844,
                    47.80600671017757
                ],
                [
                    18.873310089111328,
                    47.80583376716645
                ],
                [
                    18.880348205566406,
                    47.80502669216753
                ],
                [
                    18.88498306274414,
                    47.80416195503863
                ],
                [
                    18.887128829956055,
                    47.80358545562179
                ],
                [
                    18.888587951660156,
                    47.803470154970654
                ],
                [
                    18.890047073364258,
                    47.80370075601701
                ],
                [
                    18.890819549560547,
                    47.80393135603966
                ]
            ]
          }
          throw new Error("Not defined.")
      }

      function getTravelled() {
          return {
        "type": "LineString",
        "coordinates": [
          [
            18.87489795684814,
            47.80174061449277
          ],
          [
            18.874447345733643,
            47.80175502756803
          ],
          [
            18.874082565307617,
            47.80176944063926
          ],
          [
            18.87376070022583,
            47.80181267982903
          ],
          [
            18.873353004455566,
            47.80185591898276
          ],
          [
            18.873074054718018,
            47.80189915810052
          ],
          [
            18.872687816619873,
            47.80201446223864
          ],
          [
            18.87230157852173,
            47.80215859205136
          ],
          [
            18.8719367980957,
            47.80228830854092
          ],
          [
            18.871593475341797,
            47.80251891483372
          ],
          [
            18.87122869491577,
            47.802691868881496
          ],
          [
            18.870713710784912,
            47.80296571161285
          ],
          [
            18.86998414993286,
            47.803153076860426
          ],
          [
            18.86925458908081,
            47.803326028796846
          ],
          [
            18.86873960494995,
            47.803455742371284
          ],
          [
            18.868117332458496,
            47.80368634348159
          ],
          [
            18.867645263671875,
            47.803873706129956
          ],
          [
            18.86717319488525,
            47.8041187178043
          ],
          [
            18.866937160491943,
            47.80442137768884
          ],
          [
            18.866829872131348,
            47.804752860300894
          ],
          [
            18.866829872131348,
            47.805127577228156
          ],
          [
            18.86698007583618,
            47.8054590553336
          ],
          [
            18.867452144622803,
            47.80574729544494
          ],
          [
            18.867859840393066,
            47.805977886382344
          ],
          [
            18.86852502822876,
            47.806064357719976
          ],
          [
            18.86914730072021,
            47.80609318146718
          ],
          [
            18.869898319244385,
            47.80609318146718
          ],
          [
            18.870606422424316,
            47.80609318146718
          ],
          [
            18.871078491210938,
            47.80604994584038
          ],
          [
            18.871614933013916,
            47.80600671017757
          ],
          [
            18.87243032455444,
            47.80596347447875
          ],
          [
            18.873095512390137,
            47.80596347447875
          ],
          [
            18.873825073242188,
            47.805977886382344
          ],
          [
            18.874490261077877,
            47.805992298281964
          ],
          [
            18.875133991241455,
            47.80600671017757
          ],
          [
            18.87549877166748,
            47.80596347447875
          ],
          [
            18.87601375579834,
            47.805891414900806
          ],
          [
            18.876442909240723,
            47.80583376716645
          ],
          [
            18.87674331665039,
            47.80576170740852
          ],
          [
            18.877129554748535,
            47.80564641158791
          ]
        ]
      }
      }
    </script>
  </head>
  <body>
    <div id="topper"><h1>Hajó controller</h1></div>
    <div id="container">
      <div id="datas">
        <table>
          <tr><th colspan="2">Sebességek</th></tr>
          <tr><td>Bal:</td><td><span id="speedlabel_left">-</span>%</td></tr>
          <tr><td>Jobb:</td><td><span id="speedlabel_right">-</span>%</td></tr>
          <tr><th colspan="2">Szenzorok</th></tr>
          <tr><td>Akku:</td><td><span id="akku_percent">-</span>% <span id="akku_charging">[merítés]</span></td></tr>
          <tr><td>Akku:</td><td><span id="akku_temp">-</span> °C</td></tr>
          <tr><td>Levegő:</td><td><span id="air_temp">-</span> °C</td></tr>
          <tr><td>Víz:</td><td><span id="water_temp">-</span> °C</td></tr>
          <tr><th colspan="2">Vízszint</th></tr>
          <tr><td>&uarr;BE<span class="red" id="water_ulf"></span></td><td>&uarr;JE<span class="red" id="water_urf"></span></td></tr>
          <tr><td>&uarr;BH<span class="red" id="water_ulb"></span></td><td>&uarr;JH<span class="red" id="water_urb"></span></td></tr>
          <tr><td>&darr;BE <span class="red" id="water_blf"></span></td><td>&darr;JE <span class="red" id="water_brf"></span></td></tr>
          <tr><td>&darr;BH <span class="red" id="water_blb"></span></td><td>&darr;JH <span class="red" id="water_brb"></span></td></tr>
        </table>
      </div>
      <div id="datas">
        <table>
          <tr><th colspan="2">Vezérlő</th></tr>
          <tr><td>Állapot:</td><td><span id="auto_state">-</span></td></tr>
          <tr><td>Következő:</td><td><span id="auto_next">-</span></td></tr>
          <tr><td>Progress:</td><td><span id="auto_prigress">-</span>%</td></tr>
          <tr><td colspan="2"><label>Init</label></td></tr>
        </table>
        <table>
          <tr><th colspan="2">Iránytű</th></tr>
          <tr><td>Gyorsulás:</td><td><span id="c_acc">-</span>m/s</td></tr>
          <tr><td>Sebesség:</td><td><span id="c_velocity">-</span>m/s</td></tr>
          <tr><td>Fok:</td><td><span id="c_degx">-</span>°</td></tr>
        </table>
        <table>
            <tr><th colspan="2">GPS</th></tr>
            <tr><td>Lat:</td><td><span id="gps_lat">-</span></td></tr>
            <tr><td>Lon:</td><td><span id="gps_lng">-</span></td></tr>
            <tr><td>Satellites:</td><td><span id="gps_sats">-</span>db</td></tr>
        </table>
      </div>
      <div id="map"></div>

      <div id="answer_container">
          <pre id="answer">

          </pre>
      </div>
    </div>
    <div id="buttons_div">
      <a href="/?back_to_manual=true">Manuális vezérlés</a>
      <button onclick="map.fitBounds(route_geojsonLayer.getBounds())">Get routes to picture</button>
      <button>Refresh route</button>
      <button onclick="sendBackData({t:'s_navi'})">Start navigation</button>
    </div>
    <script>
        var map = L.map('map').setView([47.780801, 18.882331], 13);
        L.tileLayer('https://api.mapbox.com/styles/v1/mapbox/{id}/tiles/{z}/{x}/{y}?access_token={accessToken}', {
            // this.tiles = L.tileLayer('../../../4uMaps/{z}/{x}/{y}.png', {
            // attribution: 'Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, <a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>, Imagery © <a href="http://mapbox.com">Mapbox</a>',
            // maxZoom: this.gs.globalSettings.map.maxZoom,
            // minZoom: this.gs.globalSettings.map.minZoom,
            id: (new Date()).getHours() < 20 && (new Date()).getHours() > 6 ? 'light-v10' : 'dark-v10',
            accessToken: 'pk.eyJ1IjoiYXNhMjkiLCJhIjoiY2t1ZGl5a2w5MWF5czJubW83djFvZnkxbSJ9.WjYhlQPSdjbFKZRR92RS5Q'
        }).addTo(map)

        function loadLocation(coordinates) {
            location.setLatLng(coordinates)
            map.panTo(coordinates)
        }

        lastCoordinates = {lng: 18.890819549560547, lat: 47.80393135603966}

        /*location = L.marker({lng: 18.874940872192383, lat: 47.80174061449277}, {
            icon: L.icon({
                iconUrl: 'cargoship.png',
                iconSize: [50, 50]
            })
        }).addTo(map)*/
        //loadLocation({lng: 18.890819549560547, lat: 47.80393135603966})

        function loadTravelledRoad() {
            const route = getGpsRoute()
            route_geojsonLayer = L.geoJSON(route, {
            style: {
                color: '#4287f5',
                weight: 8
            }
            }).addTo(map)
            map.fitBounds(route_geojsonLayer.getBounds());

            travelled_geojsonLayer = L.geoJSON(getTravelled(), {
            style: {
                color: (new Date()).getHours() < 20 && (new Date()).getHours() > 6 ? '#ffe252' : '#ff4d4d',
                weight: 8
            }
            }).addTo(map)
        }

        loadTravelledRoad()
        
var popup = L.popup();

function onMapClick(e) {
    popup
        .setLatLng(e.latlng)
        .setContent(e.latlng.toString() +
            `<br>Distance: ${e.latlng.distanceTo(lastCoordinates).toString().split('.')[0]}m <button onclick="navigateTo([${e.latlng.lng}, ${e.latlng.lat}])">Navigate here!</button>`)
        .openOn(map);
}

function navigateTo(ln) {
    console.log('Navigating... ', ln)
    sendBackData({t:'navi', ln: ln})
    route = route_geojsonLayer.toGeoJSON(15)
    //console.log(route)
    route.features[0].geometry.coordinates.push(ln)
    route_geojsonLayer.remove()

    route_geojsonLayer = L.geoJSON(route, {
        style: {
            color: '#4287f5',
            weight: 8
        }
    }).addTo(map)
    lastCoordinates = {lng: ln[0], lat: ln[1]}
}

function travelledTo(ln) {
    console.log('Travelled to... ', ln)
    route = travelled_geojsonLayer.toGeoJSON(15)
    //console.log(route)
    route.features[0].geometry.coordinates.push(ln)
    travelled_geojsonLayer.remove()

    travelled_geojsonLayer = L.geoJSON(route, {
        style: {
            color: (new Date()).getHours() < 20 && (new Date()).getHours() > 6 ? '#ffe252' : '#ff4d4d',
            weight: 8
        }
    }).addTo(map)
}

map.on('click', onMapClick);

setTimeout(() => travelledTo([18.879653, 47.805373]), 5000)
        colors = ["#ffe252","#4287f5","#4913c9","#ff4d4d"]
      setInterval(requestData, 200);
    </script>
  </body>
</html>
)======";