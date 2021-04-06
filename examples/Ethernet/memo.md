## command

```
$ watch -n1 "curl http://169.254.0.1 2>/dev/null"
```

## circuit

voltage dividor circuit with a photoresitor (PH).
you can find `A0` value changes when you cover the top of PH.

```
5V           A0       GND
|            |        |
|--[1 kohm]--|--[PH]--|
```

## noticed

- Does the browser poll? It makes `watch-curl` slow to display the page arduino provides on the browser.
- Doc says `8 connection supported` but when I connect to it from multiple clients, the response become slow.
- atmega chip and ethernet controller become warm when accessing the web-server.
- wakeup time of the server is about ~1 sec.
