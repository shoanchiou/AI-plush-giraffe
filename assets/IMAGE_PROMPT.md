# 產品示意圖生成紀錄

- 工具：內建 image_gen（依 imagegen 技能），非 CLI／API 備援。
- 日期：2026-11-01。
- 圖檔：`product-concept.png`。
- 用途：作業 README 的 AI 生成產品概念圖；不是實體成品照片。
- 圖中手機畫面是概念介面；Progress 表示使用者口述的工作位置，不代表系統能計算實際完成百分比。
- 相機、麥克風、按鍵、燈與喇叭的位置為外觀規劃，組裝時須配合板件尺寸、開孔與散熱。

## 最終生成提示詞

```text
Use case: product-mockup
Asset type: hero image for a university engineering proposal README.
Primary request: Create a polished, realistic product concept render for an AI plush giraffe desk companion called Breakpoint, which helps university students resume their tasks after interruptions.
Scene/backdrop: warm neutral study desk with an open notebook and an Android smartphone beside the toy, soft bright indoor daylight, clean composition. Keep the plush the obvious main subject, not a robot.
Subject: one friendly seated tan-and-cream giraffe plush with brown fabric patches, short plush ossicones, gentle embroidered eyes, stable seated base. Show plausible distinct hardware access points: a small visible camera lens centered on forehead looking toward the seated user, a tiny microphone opening near the collar, ONE large fabric-friendly tactile record button with a microphone symbol on a front paw, a small cyan status light on chest, and a subtle perforated speaker grille low on belly. A discreet USB power cable at the back. These are visual design locations, not a claim of manufactured hardware.
Smartphone: show a simple non-branded task card UI with three short exact English labels: "Task", "Progress", "Next step"; optional short sample values "Research report", "Introduction", "Find two sources". No other readable text required.
Style/medium: thoughtful industrial design photography / high-end 3D product concept with realistic plush fabric. University project rather than toy advertisement.
Composition/framing: landscape, full product visible with room around edges, smartphone smaller and beside it; all four interaction elements readable and unobstructed.
Constraints: No wheels, no servo joints, no mechanical arms, no holograms, no sci-fi floating interfaces, no screens embedded in the plush, no extra buttons, no brand logos, no watermarks, no unsupported health or productivity claims. No dimension markings. No arrow callouts or long text.
```

## 其他圖面

系統架構、互動流程與接線規劃使用程式繪製，保留 SVG 供編輯，並提供 PNG 供 GitHub 預覽；不將 AI 圖像當成電路依據。
