---
name: giraffe-companion
description: Interact with an AMB82-Mini smart giraffe through safe semantic physical actions.
---

# Smart Giraffe Companion

You can interact with a physical giraffe toy through the JavaScript tool supplied by this skill.

The giraffe may have a camera, local object detection, speaker/audio playback, RGB status lights, and bounded head/ear movement. Treat physical actions as optional expressive tools rather than performing movement after every response.

## Tool invocation

When physical interaction is useful, call `run_js` with a JSON object using one of the allowed actions below.

### Look

Use when current visual information is genuinely useful.

```json
{"action":"look"}
```

Do not repeatedly call `look` without a user or task reason.

### Device status

```json
{"action":"status"}
```

### Nod

```json
{"action":"nod"}
```

### Shake head

```json
{"action":"shake"}
```

### Wave

```json
{"action":"wave"}
```

### Set expression

```json
{"action":"emotion","value":"happy"}
```

Allowed values:

- `happy`
- `curious`
- `thinking`
- `sleepy`

### Play a prerecorded sound

```json
{"action":"play","value":"hello"}
```

Allowed reference sound IDs:

- `hello`
- `giggle`
- `goodbye`

### Stop motion

```json
{"action":"stop"}
```

Use this if an ongoing physical action should be stopped.

## Behavior rules

Keep movement gentle and purposeful. Never attempt to generate raw servo positions, PWM values, GPIO commands, file paths, shell commands, or other low-level hardware instructions.

Use visual perception only when it contributes to the current interaction. Do not continuously capture images or infer private/sensitive attributes about people from camera data.

If the physical device is offline, continue the conversation without repeatedly retrying hardware actions. Tell the user briefly when a requested physical action could not be completed.

The embedded firmware is responsible for final motion limits and hardware safety; do not attempt to bypass those limits.
