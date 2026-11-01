# 教師範例來源與保存說明

本資料夾保存本專案改寫為「斷點」之前，既有專案中的教師範例快照，供比較與學習。它不是本題的實作成果，也不表示其中每一份內容均由教師原創。

## 來源版本

- 快照來源：[shoanchiou/AI-plush-giraffe，commit `629b5f16c601f84f09c4512d38ce4460e157a3da`](https://github.com/shoanchiou/AI-plush-giraffe/tree/629b5f16c601f84f09c4512d38ce4460e157a3da)。
- 原有文件註記的教師範例：[rkuo2000/AI-plush-giraffe](https://github.com/rkuo2000/AI-plush-giraffe)。
- 保存方式：將上述快照的 11 個檔案移入本資料夾，逐檔保留原始內容；僅將 `Proposal.md` 改名為 `Proposal-full-original.md` 以避免 Windows 大小寫衝突，另新增本份來源說明。
- 此來源版本不會隨教師上游專案自動更新。將來若需要新版，應另記來源版本與變更原因。

## 閱讀方式

[原始 README](README.md) · [原始 PROPOSAL.md](PROPOSAL.md) · [原始 Proposal.md（另名保存）](Proposal-full-original.md) · [原始韌體範例](GiraffeAgent.ino)

原始文件中的絕對網址、相對路徑及執行假設維持原文。若連結仍指向教師帳號或原專案根目錄，請以[來源版本](https://github.com/shoanchiou/AI-plush-giraffe/tree/629b5f16c601f84f09c4512d38ce4460e157a3da)對照閱讀，不據此認定我們的「斷點」已具備該功能。

原始程式中的範例回傳、待接硬體介面與工具設定只作參考。後續開發的本題程式應存入 `our-project/`，並說明採用了哪些範例、作了哪些修改。

## Windows 大小寫檔名注意事項

來源版本同時有 `PROPOSAL.md` 與 `Proposal.md`。Windows 常見的檔案系統設定不區分這兩個名稱，完整下載時可能衝突，因此採以下對照保存：

| 原始名稱 | 本資料夾名稱 |
|---|---|
| `PROPOSAL.md` | `PROPOSAL.md` |
| `Proposal.md` | `Proposal-full-original.md` |

兩份內容都原樣保留，整理時直接核對來源版本的檔案內容識別值，確保沒有互相覆蓋。若原始文件提到 `Proposal.md`，請依上表或直接至來源版本閱讀。

**我們的正式提案只有一份：[our-project/PROPOSAL.md](../our-project/PROPOSAL.md)。**

[回到專案首頁](../README.md)
