# Temperature and Humidity Interface — Version 2

- `interface-v2-flow.json` contains the flow for FlowFuse Dashboard 2.
- `dashboard-template.html` contains the source for the flow’s **Dashboard layout** node.
- `preview.html` opens in a browser with sample readings and requires no connection.

For a fresh setup, install FlowFuse Dashboard 2 in Node-RED, import the flow, and check
the MQTT broker settings. Deploy and open `/monitor/dashboard`.

To update a deployed Version 1, paste `dashboard-template.html` into its **Dashboard layout**
node and deploy. This keeps your existing broker settings.

To check the dashboard without hardware, click **Test: send one example reading** twice.
The first click shows both values. The second draws both trend lines.
