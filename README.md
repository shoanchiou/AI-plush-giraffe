# 斷點｜AI 長頸鹿任務續接夥伴

以 AMB82-mini 與 Android 裝置端 AI，協助大學生在離席返回後接回最後一次記下的任務進度。

**作業閱讀入口：[完整專題提案](our-project/PROPOSAL.md) · [產品與架構說明](our-project/README.md)**

## 專案分區

| 資料夾 | 內容 | 如何閱讀 |
|---|---|---|
| [`our-project/`](our-project/) | 我們的「斷點」提案、README、產品概念圖、架構與接線規劃 | 本專題的正式文件與後續成果放在這裡。 |
| [`teacher-reference/`](teacher-reference/) | 修改前既有專案中的教師範例快照，含原始文件、程式與圖片 | 僅供對照學習；來源及保留方式見 [SOURCE.md](teacher-reference/SOURCE.md)。 |

兩個資料夾分開保存，避免把範例程式當成本題的實作成果。後續只在 `our-project/` 逐步加入本題的程式、硬體與測試資料。

## 目前收錄內容

- [專題提案](our-project/PROPOSAL.md)：動機、功能、技術分工、開發規劃與驗證方法。
- [產品與架構說明](our-project/README.md)：AI 生成產品概念圖、系統方塊圖、互動流程及接線規劃。
- [架構與電路規劃](our-project/Architecture.md)：板端、手機、模型與音訊通訊的分工。
- [進度與後續填寫方式](our-project/PROGRESS.md)：哪些資料已收錄、後續成果放在哪裡。

目前收錄的是提案與設計圖面，尚未收錄本題的韌體、Android App、硬體組裝紀錄或實測結果。文件中的操作流程與測試數值屬設計規劃，產品圖為 AI 生成概念圖。

## 資料夾結構

```text
README.md                 本頁：作業入口與資料夾導覽
PROPOSAL.md               保留原提案網址的閱讀入口
our-project/              我們的正式內容
  PROPOSAL.md
  README.md
  Architecture.md
  PROGRESS.md
  assets/
teacher-reference/        既有教師範例的原文快照
  SOURCE.md               來源版本、保存及閱讀說明
  README.md
  PROPOSAL.md / Proposal-full-original.md
  GiraffeAgent.ino
  Architecture.md
  SKILL.md
  scripts/
  assets/
```

教師範例保留原文與原始連結；本題文件內的圖片及連結則隨 `our-project/` 一起移動。原範例中僅大小寫不同的其中一份提案已重新命名，避免 Windows 下載衝突；對照方式見 [來源說明](teacher-reference/SOURCE.md)。
